#include <iostream>
#include <string>
#include "caffe.pb.h"
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <glog/logging.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>

const int kProtoReadBytesLimit = INT_MAX;

using google::protobuf::io::FileInputStream;
using google::protobuf::io::FileOutputStream;
using google::protobuf::io::ZeroCopyInputStream;
using google::protobuf::io::CodedInputStream;
using google::protobuf::io::ZeroCopyOutputStream;
using google::protobuf::io::CodedOutputStream;
using google::protobuf::Message;


using namespace std;

//从txt文件中读取proto消息函数 成功返回true
bool ReadProtoFromTextFile(const char* filename, Message* proto) {
    //以只读方式(O_RDONLY)打开filename文件
    int fd = open(filename, O_RDONLY);
    //使用glog库中的CHECK_NE函数检查是否读取文件成功
    CHECK_NE(fd, -1) << "File not found: " << filename;
    //使用FileInputStream流读取文件
    FileInputStream* input = new FileInputStream(fd);
    //使用Text格式解析input输入,并将读取到的数据赋值到proto上
    bool success = google::protobuf::TextFormat::Parse(input, proto);
    //释放input对象
    delete input;
    //关闭stream流
    close(fd);
    //返回是否成功
    return success;
}

//将proto消息写入txt文件中
void WriteProtoToTextFile(const Message& proto, const char* filename) {
    //0644表示文件的权限
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    FileOutputStream* output = new FileOutputStream(fd);
    CHECK(google::protobuf::TextFormat::Print(proto, output));
    delete output;
    close(fd);
}

//从二进制文件中读取proto消息函数 成功返回true
bool ReadProtoFromBinaryFile(const char* filename, Message* proto) {
    int fd = open(filename, O_RDONLY);
    CHECK_NE(fd, -1) << "File not found: " << filename;
    ZeroCopyInputStream* raw_input = new FileInputStream(fd);
    CodedInputStream* coded_input = new CodedInputStream(raw_input);
    //proto文件读取二进制默认最大大小为64M,所以我们需要设置通过SetTotalBytesLimit函数设置一下最大值,其中kProtoReadBytesLimit设置上限，而第二个参数536870912设置读取文件超过这个值会产生警报
    coded_input->SetTotalBytesLimit(kProtoReadBytesLimit, 536870912);
    bool success = proto->ParseFromCodedStream(coded_input);
    delete coded_input;
    delete raw_input;
    close(fd);
    return success;
}

//向二进制文件中写入proto消息函数
void WriteProtoToBinaryFile(const Message& proto, const char* filename) {
    fstream output(filename, ios::out | ios::trunc | ios::binary);
    CHECK(proto.SerializeToOstream(&output));
}


int main(int argc, char* argv[]) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    //调用caffe.pb.h中的Person类，并设置id以及name，通过调用add_phone()来添加number
    caffe::Person person;
    person.set_id(10421);
    person.set_name("hopo");
    person.set_email("2381892713@qq.com");

    //添加person中的phone 默认类型为HOME
    caffe::Person::PhoneNumber* phonenumber = person.add_phone();
    phonenumber->set_number("17601001773");

    phonenumber = person.add_phone();
    phonenumber->set_number("13261009856");
    phonenumber->set_type(caffe::Person::PhoneType::Person_PhoneType_WORK);

    phonenumber = person.add_phone();
    phonenumber->set_number("15660195460");
    phonenumber->set_type(caffe::Person::PhoneType::Person_PhoneType_MOBILE);


    WriteProtoToTextFile(person, "../re.txt");

    string serializedStr;
    //序列化person到serializedStr中
    person.SerializeToString(&serializedStr);
    cout<<"serialization result: "<<serializedStr<<endl;
    cout<<endl<<"debugString: "<<person.DebugString();




    //通过serializedStr反序列化
    //从serializedStr中读取person
    caffe::Person deserializedPerson;
    if(!deserializedPerson.ParseFromString(serializedStr)) {
        cerr << "Failed to parse student." <<endl;
        return -1;
    }


    cout<<"person id: "<<deserializedPerson.id()<<endl;
    cout<<"person name: "<<deserializedPerson.name()<<endl;
    cout<<"person email: "<<deserializedPerson.email()<<endl;
    for (int i = 0; i < deserializedPerson.phone_size(); i++){
        const caffe::Person_PhoneNumber phone_number = deserializedPerson.phone(i);
        switch (phone_number.type()) {
            case caffe::Person::HOME:
                cout<<"Home phone #: ";
                break;
            case caffe::Person::WORK:
                cout<<"Work #: ";
                break;
            case caffe::Person::MOBILE:
                cout<<"Mobile #: ";
                break;
        }
        cout<<phone_number.number()<<endl;
    }


    google::protobuf::ShutdownProtobufLibrary();

}
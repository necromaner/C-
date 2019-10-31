#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * des.h provides the following functions and constants:
 *
 * generate_key, generate_sub_keys, process_message, ENCRYPTION_MODE, DECRYPTION_MODE
 *
 */
#include "des.h"

// Declare file handlers
static FILE *key_file, *input_file, *output_file;

// Declare action parameters
#define ACTION_GENERATE_KEY "-g"
#define ACTION_ENCRYPT "-e"
#define ACTION_DECRYPT "-d"

// DES key is 8 bytes long
int main11() {
    //argc所带参数数量 1为不带参数
    //argv[]为所带参数，空格

    int argc;
    char* argv[5];
    int x=0;
    switch (x){
        case 0:
            argc=3;
            argv[1]="-g";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            break;
        case 1:
            argc=5;
            argv[1]="-e";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.txt";
            argv[4]="/Users/necromaner/tmp/sample.enc";
            break;
        case 2:
            argc=5;
            argv[1]="-d";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.enc";
            argv[4]="/Users/necromaner/tmp/sample_decrypted.txt";
            break;
    }

    clock_t start, finish;
    double time_taken;
    unsigned long file_size;
    unsigned short int padding;

    //没有参数
    if (argc < 2) {
//        printf("You must provide at least 1 parameter, where you specify the action.");
        printf("必须提供至少一个参数，在其中指定操作。");
        return 1;
    }

    if (strcmp(argv[1], ACTION_GENERATE_KEY) == 0) { // Generate key file 生成密钥
        if (argc != 3) {
//            printf("Invalid # of parameter specified. Usage: run_des -g keyfile.key");
            printf("指定参数的#无效。用法:run_des -g keyfile.key");
            return 1;
        }

        key_file = fopen(argv[2], "wb");
        if (!key_file) {
//            printf("Could not open file to write key.");
            printf("无法打开文件写入密钥。");
            return 1;
        }

        unsigned int iseed = (unsigned int)time(NULL);
        srand (iseed);

        short int bytes_written;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        generate_key(des_key);
        bytes_written = fwrite(des_key, 1, DES_KEY_SIZE, key_file);
        if (bytes_written != DES_KEY_SIZE) {
//            printf("Error writing key to output file.");
            printf("向输出文件写入键出错。");
            fclose(key_file);
            free(des_key);
            return 1;
        }

        free(des_key);
        fclose(key_file);
    } else if ((strcmp(argv[1], ACTION_ENCRYPT) == 0) || (strcmp(argv[1], ACTION_DECRYPT) == 0)) { // Encrypt or decrypt 加密解密
        if (argc != 5) {
//            printf("Invalid # of parameters (%d) specified. Usage: run_des [-e|-d] keyfile.key input.file output.file", argc);
            printf("指定的参数(%d)的#无效。用法:run_des [-e|-d]密钥文件。关键的输入。文件output.file", argc);
            return 1;
        }

        // Read key file
        key_file = fopen(argv[2], "rb");
        if (!key_file) {
//            printf("Could not open key file to read key.");
            printf("无法打开密钥文件读取密钥。");
            return 1;
        }

        short int bytes_read;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        bytes_read = fread(des_key, sizeof(unsigned char), DES_KEY_SIZE, key_file);
        if (bytes_read != DES_KEY_SIZE) {
//            printf("Key read from key file does nto have valid key size.");
            printf("从密钥文件中读取的密钥不具有有效的密钥大小.");
            fclose(key_file);
            return 1;
        }
        fclose(key_file);

        // Open input file
        input_file = fopen(argv[3], "rb");
        if (!input_file) {
//            printf("Could not open input file to read data.");
            printf("无法打开输入文件读取数据.");
            return 1;
        }

        // Open output file
        output_file = fopen(argv[4], "wb");
        if (!output_file) {
//            printf("Could not open output file to write data.");
            printf("无法打开输出文件写入数据.");
            return 1;
        }

        // Generate DES key set
        short int bytes_written, process_mode;
        unsigned long block_count = 0, number_of_blocks;
        unsigned char* data_block = (unsigned char*) malloc(8*sizeof(char));
        unsigned char* processed_block = (unsigned char*) malloc(8*sizeof(char));
        key_set* key_sets = (key_set*)malloc(17*sizeof(key_set));

        start = clock();
        generate_sub_keys(des_key, key_sets);
        finish = clock();
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;

        // Determine process mode
        if (strcmp(argv[1], ACTION_ENCRYPT) == 0) {
            process_mode = ENCRYPTION_MODE;
//            printf("Encrypting..\n");
            printf("加密..\n");
        } else {
            process_mode = DECRYPTION_MODE;
//            printf("Decrypting..\n");
            printf("解密..\n");
        }

        // Get number of blocks in the file
        fseek(input_file, 0L, SEEK_END);
        file_size = ftell(input_file);

        fseek(input_file, 0L, SEEK_SET);
        number_of_blocks = file_size/8 + ((file_size%8)?1:0);

        start = clock();

        // Start reading input file, process and write to output file
        while(fread(data_block, 1, 8, input_file)) {
            block_count++;
            if (block_count == number_of_blocks) {
                if (process_mode == ENCRYPTION_MODE) {
                    padding = 8 - file_size%8;
                    if (padding < 8) { // Fill empty data block bytes with padding
                        memset((data_block + 8 - padding), (unsigned char)padding, padding);
                    }

                    process_message(data_block, processed_block, key_sets, process_mode);
                    bytes_written = fwrite(processed_block, 1, 8, output_file);

                    if (padding == 8) { // Write an extra block for padding
                        memset(data_block, (unsigned char)padding, 8);
                        process_message(data_block, processed_block, key_sets, process_mode);
                        bytes_written = fwrite(processed_block, 1, 8, output_file);
                    }
                } else {
                    process_message(data_block, processed_block, key_sets, process_mode);
                    padding = processed_block[7];

                    if (padding < 8) {
                        bytes_written = fwrite(processed_block, 1, 8 - padding, output_file);
                    }
                }
            } else {
                process_message(data_block, processed_block, key_sets, process_mode);
                bytes_written = fwrite(processed_block, 1, 8, output_file);
            }
            memset(data_block, 0, 8);
        }

        finish = clock();

        // Free up memory
        free(des_key);
        free(data_block);
        free(processed_block);
        fclose(input_file);
        fclose(output_file);

        // Provide feedback
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;
//        printf("Finished processing %s. Time taken: %lf seconds.\n", argv[3], time_taken);
        printf("完成处理 %s. 时间: %lf 秒.\n", argv[3], time_taken);
        return 0;
    } else {
//        printf("Invalid action: %s. First parameter must be [ -g | -e | -d ].", argv[1]);
        printf("无效的行动:%s。第一个参数必须是[-g | -e | -d]。", argv[1]);
        return 1;
    }

    return 0;
}
int main22() {
    //argc所带参数数量 1为不带参数
    //argv[]为所带参数，空格

    int argc;
    char* argv[5];
    int x=1;
    switch (x){
        case 0:
            argc=3;
            argv[1]="-g";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            break;
        case 1:
            argc=5;
            argv[1]="-e";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.txt";
            argv[4]="/Users/necromaner/tmp/sample.enc";
            break;
        case 2:
            argc=5;
            argv[1]="-d";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.enc";
            argv[4]="/Users/necromaner/tmp/sample_decrypted.txt";
            break;
    }

    clock_t start, finish;
    double time_taken;
    unsigned long file_size;
    unsigned short int padding;

    //没有参数
    if (argc < 2) {
//        printf("You must provide at least 1 parameter, where you specify the action.");
        printf("必须提供至少一个参数，在其中指定操作。");
        return 1;
    }

    if (strcmp(argv[1], ACTION_GENERATE_KEY) == 0) { // Generate key file 生成密钥
        if (argc != 3) {
//            printf("Invalid # of parameter specified. Usage: run_des -g keyfile.key");
            printf("指定参数的#无效。用法:run_des -g keyfile.key");
            return 1;
        }

        key_file = fopen(argv[2], "wb");
        if (!key_file) {
//            printf("Could not open file to write key.");
            printf("无法打开文件写入密钥。");
            return 1;
        }

        unsigned int iseed = (unsigned int)time(NULL);
        srand (iseed);

        short int bytes_written;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        generate_key(des_key);
        bytes_written = fwrite(des_key, 1, DES_KEY_SIZE, key_file);
        if (bytes_written != DES_KEY_SIZE) {
//            printf("Error writing key to output file.");
            printf("向输出文件写入键出错。");
            fclose(key_file);
            free(des_key);
            return 1;
        }

        free(des_key);
        fclose(key_file);
    } else if ((strcmp(argv[1], ACTION_ENCRYPT) == 0) || (strcmp(argv[1], ACTION_DECRYPT) == 0)) { // Encrypt or decrypt 加密解密
        if (argc != 5) {
//            printf("Invalid # of parameters (%d) specified. Usage: run_des [-e|-d] keyfile.key input.file output.file", argc);
            printf("指定的参数(%d)的#无效。用法:run_des [-e|-d]密钥文件。关键的输入。文件output.file", argc);
            return 1;
        }

        // Read key file
        key_file = fopen(argv[2], "rb");
        if (!key_file) {
//            printf("Could not open key file to read key.");
            printf("无法打开密钥文件读取密钥。");
            return 1;
        }

        short int bytes_read;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        bytes_read = fread(des_key, sizeof(unsigned char), DES_KEY_SIZE, key_file);
        if (bytes_read != DES_KEY_SIZE) {
//            printf("Key read from key file does nto have valid key size.");
            printf("从密钥文件中读取的密钥不具有有效的密钥大小.");
            fclose(key_file);
            return 1;
        }
        fclose(key_file);

        // Open input file
        input_file = fopen(argv[3], "rb");
        if (!input_file) {
//            printf("Could not open input file to read data.");
            printf("无法打开输入文件读取数据.");
            return 1;
        }

        // Open output file
        output_file = fopen(argv[4], "wb");
        if (!output_file) {
//            printf("Could not open output file to write data.");
            printf("无法打开输出文件写入数据.");
            return 1;
        }

        // Generate DES key set
        short int bytes_written, process_mode;
        unsigned long block_count = 0, number_of_blocks;
        unsigned char* data_block = (unsigned char*) malloc(8*sizeof(char));
        unsigned char* processed_block = (unsigned char*) malloc(8*sizeof(char));
        key_set* key_sets = (key_set*)malloc(17*sizeof(key_set));

        start = clock();
        generate_sub_keys(des_key, key_sets);
        finish = clock();
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;

        // Determine process mode
        if (strcmp(argv[1], ACTION_ENCRYPT) == 0) {
            process_mode = ENCRYPTION_MODE;
//            printf("Encrypting..\n");
            printf("加密..\n");
        } else {
            process_mode = DECRYPTION_MODE;
//            printf("Decrypting..\n");
            printf("解密..\n");
        }

        // Get number of blocks in the file
        fseek(input_file, 0L, SEEK_END);
        file_size = ftell(input_file);

        fseek(input_file, 0L, SEEK_SET);
        number_of_blocks = file_size/8 + ((file_size%8)?1:0);

        start = clock();

        // Start reading input file, process and write to output file
        while(fread(data_block, 1, 8, input_file)) {
            block_count++;
            if (block_count == number_of_blocks) {
                if (process_mode == ENCRYPTION_MODE) {
                    padding = 8 - file_size%8;
                    if (padding < 8) { // Fill empty data block bytes with padding
                        memset((data_block + 8 - padding), (unsigned char)padding, padding);
                    }

                    process_message(data_block, processed_block, key_sets, process_mode);
                    bytes_written = fwrite(processed_block, 1, 8, output_file);

                    if (padding == 8) { // Write an extra block for padding
                        memset(data_block, (unsigned char)padding, 8);
                        process_message(data_block, processed_block, key_sets, process_mode);
                        bytes_written = fwrite(processed_block, 1, 8, output_file);
                    }
                } else {
                    process_message(data_block, processed_block, key_sets, process_mode);
                    padding = processed_block[7];

                    if (padding < 8) {
                        bytes_written = fwrite(processed_block, 1, 8 - padding, output_file);
                    }
                }
            } else {
                process_message(data_block, processed_block, key_sets, process_mode);
                bytes_written = fwrite(processed_block, 1, 8, output_file);
            }
            memset(data_block, 0, 8);
        }

        finish = clock();

        // Free up memory
        free(des_key);
        free(data_block);
        free(processed_block);
        fclose(input_file);
        fclose(output_file);

        // Provide feedback
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;
//        printf("Finished processing %s. Time taken: %lf seconds.\n", argv[3], time_taken);
        printf("完成处理 %s. 时间: %lf 秒.\n", argv[3], time_taken);
        return 0;
    } else {
//        printf("Invalid action: %s. First parameter must be [ -g | -e | -d ].", argv[1]);
        printf("无效的行动:%s。第一个参数必须是[-g | -e | -d]。", argv[1]);
        return 1;
    }

    return 0;
}
int main33() {
    //argc所带参数数量 1为不带参数
    //argv[]为所带参数，空格

    int argc;
    char* argv[5];
    int x=2;
    switch (x){
        case 0:
            argc=3;
            argv[1]="-g";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            break;
        case 1:
            argc=5;
            argv[1]="-e";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.txt";
            argv[4]="/Users/necromaner/tmp/sample.enc";
            break;
        case 2:
            argc=5;
            argv[1]="-d";
            argv[2]="/Users/necromaner/tmp/keyfile.key";
            argv[3]="/Users/necromaner/tmp/sample.enc";
            argv[4]="/Users/necromaner/tmp/sample_decrypted.txt";
            break;
    }

    clock_t start, finish;
    double time_taken;
    unsigned long file_size;
    unsigned short int padding;

    //没有参数
    if (argc < 2) {
//        printf("You must provide at least 1 parameter, where you specify the action.");
        printf("必须提供至少一个参数，在其中指定操作。");
        return 1;
    }

    if (strcmp(argv[1], ACTION_GENERATE_KEY) == 0) { // Generate key file 生成密钥
        if (argc != 3) {
//            printf("Invalid # of parameter specified. Usage: run_des -g keyfile.key");
            printf("指定参数的#无效。用法:run_des -g keyfile.key");
            return 1;
        }

        key_file = fopen(argv[2], "wb");
        if (!key_file) {
//            printf("Could not open file to write key.");
            printf("无法打开文件写入密钥。");
            return 1;
        }

        unsigned int iseed = (unsigned int)time(NULL);
        srand (iseed);

        short int bytes_written;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        generate_key(des_key);
        bytes_written = fwrite(des_key, 1, DES_KEY_SIZE, key_file);
        if (bytes_written != DES_KEY_SIZE) {
//            printf("Error writing key to output file.");
            printf("向输出文件写入键出错。");
            fclose(key_file);
            free(des_key);
            return 1;
        }

        free(des_key);
        fclose(key_file);
    } else if ((strcmp(argv[1], ACTION_ENCRYPT) == 0) || (strcmp(argv[1], ACTION_DECRYPT) == 0)) { // Encrypt or decrypt 加密解密
        if (argc != 5) {
//            printf("Invalid # of parameters (%d) specified. Usage: run_des [-e|-d] keyfile.key input.file output.file", argc);
            printf("指定的参数(%d)的#无效。用法:run_des [-e|-d]密钥文件。关键的输入。文件output.file", argc);
            return 1;
        }

        // Read key file
        key_file = fopen(argv[2], "rb");
        if (!key_file) {
//            printf("Could not open key file to read key.");
            printf("无法打开密钥文件读取密钥。");
            return 1;
        }

        short int bytes_read;
        unsigned char* des_key = (unsigned char*) malloc(8*sizeof(char));
        bytes_read = fread(des_key, sizeof(unsigned char), DES_KEY_SIZE, key_file);
        if (bytes_read != DES_KEY_SIZE) {
//            printf("Key read from key file does nto have valid key size.");
            printf("从密钥文件中读取的密钥不具有有效的密钥大小.");
            fclose(key_file);
            return 1;
        }
        fclose(key_file);

        // Open input file
        input_file = fopen(argv[3], "rb");
        if (!input_file) {
//            printf("Could not open input file to read data.");
            printf("无法打开输入文件读取数据.");
            return 1;
        }

        // Open output file
        output_file = fopen(argv[4], "wb");
        if (!output_file) {
//            printf("Could not open output file to write data.");
            printf("无法打开输出文件写入数据.");
            return 1;
        }

        // Generate DES key set
        short int bytes_written, process_mode;
        unsigned long block_count = 0, number_of_blocks;
        unsigned char* data_block = (unsigned char*) malloc(8*sizeof(char));
        unsigned char* processed_block = (unsigned char*) malloc(8*sizeof(char));
        key_set* key_sets = (key_set*)malloc(17*sizeof(key_set));

        start = clock();
        generate_sub_keys(des_key, key_sets);
        finish = clock();
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;

        // Determine process mode
        if (strcmp(argv[1], ACTION_ENCRYPT) == 0) {
            process_mode = ENCRYPTION_MODE;
//            printf("Encrypting..\n");
            printf("加密..\n");
        } else {
            process_mode = DECRYPTION_MODE;
//            printf("Decrypting..\n");
            printf("解密..\n");
        }

        // Get number of blocks in the file
        fseek(input_file, 0L, SEEK_END);
        file_size = ftell(input_file);

        fseek(input_file, 0L, SEEK_SET);
        number_of_blocks = file_size/8 + ((file_size%8)?1:0);

        start = clock();

        // Start reading input file, process and write to output file
        while(fread(data_block, 1, 8, input_file)) {
            block_count++;
            if (block_count == number_of_blocks) {
                if (process_mode == ENCRYPTION_MODE) {
                    padding = 8 - file_size%8;
                    if (padding < 8) { // Fill empty data block bytes with padding
                        memset((data_block + 8 - padding), (unsigned char)padding, padding);
                    }

                    process_message(data_block, processed_block, key_sets, process_mode);
                    bytes_written = fwrite(processed_block, 1, 8, output_file);

                    if (padding == 8) { // Write an extra block for padding
                        memset(data_block, (unsigned char)padding, 8);
                        process_message(data_block, processed_block, key_sets, process_mode);
                        bytes_written = fwrite(processed_block, 1, 8, output_file);
                    }
                } else {
                    process_message(data_block, processed_block, key_sets, process_mode);
                    padding = processed_block[7];

                    if (padding < 8) {
                        bytes_written = fwrite(processed_block, 1, 8 - padding, output_file);
                    }
                }
            } else {
                process_message(data_block, processed_block, key_sets, process_mode);
                bytes_written = fwrite(processed_block, 1, 8, output_file);
            }
            memset(data_block, 0, 8);
        }

        finish = clock();

        // Free up memory
        free(des_key);
        free(data_block);
        free(processed_block);
        fclose(input_file);
        fclose(output_file);

        // Provide feedback
        time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;
//        printf("Finished processing %s. Time taken: %lf seconds.\n", argv[3], time_taken);
        printf("完成处理 %s. 时间: %lf 秒.\n", argv[3], time_taken);
        return 0;
    } else {
//        printf("Invalid action: %s. First parameter must be [ -g | -e | -d ].", argv[1]);
        printf("无效的行动:%s。第一个参数必须是[-g | -e | -d]。", argv[1]);
        return 1;
    }

    return 0;
}

int main() {

//    main11();
//    main22();
    main33();
    return 0;
}



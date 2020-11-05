#include <gtest/gtest.h>

#include "EyerAV/EyerAV.hpp"

TEST(A, ATest){
    Eyer::EyerAVReader reader("rtmp://redknot.cn:1935/demo/aaa");
    int ret = reader.Open();
    if(ret){
        printf("Open Fail ret: %d\n", ret);
        return;
    }

    int streamCount = reader.GetStreamCount();
    printf("Stream Count: %d\n", streamCount);

    reader.Close();
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

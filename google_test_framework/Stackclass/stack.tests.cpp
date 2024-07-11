#include "Stacks.h"
#include <gtest/gtest.h>


using namespace ::testing;


class StackTesting : public ::testing::Test
{
    public:
    //testing fixtures
        void SetUp()override
        {
            std::cout<<"Setup\n";
        }

        void TearDown()override
        {
            std::cout<<"Tear down\n";
        }

};

TEST_F(StackTesting,pushpop_test)
{
    Stacks<int> stacktest;
    int pushvalues;
    stacktest.push(1);
    stacktest.pop(pushvalues);


    ASSERT_EQ(pushvalues,1);
}
TEST_F(StackTesting,isempty_test)
{
    Stacks<int> stacktest;



    ASSERT_EQ(stacktest.isStackEmpty(),true);
}


TEST_F(StackTesting,print_test)
{
    Stacks<int> stacktest;
    int pushvalues;
    stacktest.push(1);
    std::string expectedvalue="The list is: 1 \n\n";
//flush the cout buffer to make sure we only capture what we need from the stacktest.printstack() function call
    std::cout.flush();
//start the capture of stdout from gtest's side
    testing::internal::CaptureStdout();
//function call
    stacktest.printStack();
//get the captured stdout
    std::string output= testing::internal::GetCapturedStdout();



//compare 
    EXPECT_EQ(output,expectedvalue);
}


TEST_F(StackTesting,top_test)
{
    Stacks<int> stacktest;
    stacktest.push(1);


    ASSERT_EQ(stacktest.Top(),1);
}
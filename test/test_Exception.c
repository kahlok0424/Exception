#include "unity.h"
#include "Exception.h"
#include "CException.h"

#define ERR_OUT_OF_BOUND    3

void setUp(void)
{
}

void tearDown(void)
{
}

char *names[]={
  "Ali",
  "David",
  "Zhe Hao",
  "Jane"
};

char *namesInIntel[] = {
  "Alvin",
  "Botak",
  "Cat",
  "Desmond"
};

char *namesInNXP[] = {
  "Edmund",
  "Fiona",
  "Gx",
  "Hanson"
};

char *getName(int index){
  if(index >= 4)
    //Throw(ERR_OUT_OF_BOUND);
    return names[index];
}

void test_Exception_Given_1_Expect_error_code(void)
{
    CEXCEPTION_T  e;
    char *name;

    Try{
      name = getName(1);
      //printf("Name is : %s",name);
      TEST_ASSERT_EQUAL_STRING("David",name);
    }Catch(e){
      printf("Error code : %d",e);
    }
}

void test_Exception_Given_1_Expect_Print_error_message(void)
{
    CEXCEPTION_T  e;
    char *name;

    Try{
      name = getName(4);
      printf("Name is : ");
      TEST_FAIL_MESSAGE("Exceptied ERR_OUT_OF_BOUND to be thrown ,but none");
    }Catch(e){
      //printf("Error code : %d",e);
    }
}

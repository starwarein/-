# 第二期题目

------

## 基于C语言的简易计算器

### 1.题目背景：

C语言是嵌入式领域最常用的编程语言，掌握C语言对于学好嵌入式非常重要．我们现在希望你能用C语言编写一个简单的计算器．  

### 2.题目内容：

1. 程序通过标准输入读取运算式，运算结果输出到标准输出（通过键盘输入运算数和运算符，屏幕上打印出来）  

2. 支持加减乘除运算操作  

3. 支持浮点数运算  

4. 不用考虑正负号，括号，算数优先级，文件操作，指数对数运算等复杂运算  

实现基本要求就可以通过本题．  

------

## 加分项：

1.支持文件操作，从文件中读取运算式  

2.支持指数运算，对数运算，幂运算等复杂运算，可以写成函数形式，例如power(2,10)=1024，也可以写成记号形式（要考虑优先级）  

3.支持正负号，括号，算数优先级（提示：可以采用一种叫做栈的数据结构，和一种叫做逆波兰表达式的算法）  

完成加分项越多，得分越高．  

4、参考资料：

如果你不知道如何入手，我们给出了以下两个参考代码：  

参考代码1非常采用标准输入输出，支持加减乘除，不支持浮点数，不支持算数优先级．你可以对于参考代码1稍微进行修改，使得程序支持浮点数运算，就可以实现基本要求．  

参考代码2支持文件操作，支持加减乘除，支持算数优先级，不支持浮点数．你也可以对代码2进行修改．  

参考代码1

```
include<stdio.h>

include<stdlib.h>

define MAX_SIZE 10

int readOperand();//读取运算数

int Operation(int operand1,char operator,int operand2);//进行运算，运算结果暂存于operand1中

int Operation(int operand1,char operator,int operand2){

  switch(operator){//根据运算符进行加,减,乘,除运算

    case '+':operand1 += operand2;
            break;
    case '-':operand1 -= operand2;
            break;
    case '*':operand1 *= operand2;
            break;
    case '/':
            if(operand2 != 0){
              operand1 /= operand2;
              break;
            }
            else{
              printf("除数不能为0");
              exit(1);
            }
    default: printf("运算符不能识别");
             exit(1);

  }

    return operand1;

}

int readOperand(){

  char temp[MAX_SIZE];

  int operand;

  scanf("%[0-9]",temp);//先读取字符串,不读换行符

  sscanf(temp,"%d",&operand);//再从字符串中读数字

  return operand;

}

int main(){

  int operand1,operand2;//运算数１，运算数２

  char operator;//运算符

  operand1 = readOperand();//读取运算数１

  operator = getchar();//读取运算符

  while(operator != '\n'){//如果运算符不是换行符，一直读

     operand2 = readOperand();
     operand1 = Operation(operand1,operator,operand2);
     operator = getchar();//读取运算符

  }

  printf("%d\n",operand1);//输出运算结果

  return 0;

}
```

参考代码1示范输入:10*12-20

示范输出:100

------

参考代码2:

```
/* cal.c

- 仅支持 + - * / int 的 C 语言计算器 (不支持正负号, ／ 为整数除法)
- (C) ES, 2016
  */

/* 样例：

- intput: 
- 1 - 6 / 3 + 8 - 3 * 10086 / 356 - 34798 + 6666 ^D
- output:
- 0 + 1 = 1
- 6 / 3 = 2
- 1 - 2 = -1
- -1 + 8 = 7
- 3 * 10086 = 30258
- 30258 / 356 = 84
- 7 - 84 = -77
- -77 - 34798 = -34875
- -34875 + 6666 = -28209
- ans = -28209
  */


include <stdio.h>

include <stdlib.h>

define type_num int

define scanf_num "%9d" /* 式子中自然数最多9位 */

define printf_num "%d"

include "assert.h"

/**

- 从 file 中读取式子(以 ^D 结束) 运算后返回结果
- 遇到错误直接退出
  */
  type_num read(FILE* file);

int main() {

    printf("ans = "printf_num"\n", read(stdin));
    return 0;

}

type_num read(FILE* file) {

    type_num num, ans = 0, oldans;
    int op1 = '+', op2;
    for (;;) { 
        if (fscanf(file, scanf_num" ", &num) != 1)
            fprintf(stderr, "不要瞎搞: 运算符 %c 后面输了个啥 1\n", op1), exit(1); /* 一开始没输数字会出现 "运算符 + 后面输了个啥 1", 待处理 */
        op2 = fgetc(file);
        head: switch (op2) {
            case '*': case '/':
             /* num = read2(num, op2, file); */
                    {
                    type_num num2, oldnum;
                    if (fscanf(file, scanf_num" ", &num2) != 1)
                        fprintf(stderr, "不要瞎搞: 运算符 %c 后面输了个啥 2\n", op2), exit(1);
                    if (op2 == '/' && num2 == 0)
                        fprintf(stderr, "%s\n", "不要瞎搞: 除0啦，哥"), exit(1);
                    oldnum = num;
                    op2 == '*' ? printf("%d * %d = %d\n", oldnum, num2, num *= num2) : printf("%d / %d = %d\n", oldnum, num2, num /= num2); /* 可能溢出, 尚未完善 */
                    }
                op2 = fgetc(file);
                goto head; /* 以新的 num & op2 返回 switch 开头 */
            case '+': case '-': case EOF:
                oldans = ans;
                op1 == '+' ? printf("%d + %d = %d\n", oldans, num, ans += num) : printf("%d - %d = %d\n", oldans, num, ans -= num); /* 可能溢出, 尚未完善 */ /* 第一次运算会输出 0 + ? ＝ ?, 待处理 */
                if (op2 == EOF)
                    return ans;
                op1 = op2;
                break;
            default : fprintf(stderr, "不要瞎搞: '%c' 这是啥运算符 \n", op2), exit(1);
        }
    }
    assert(0);

}
```

5、其他说明：
如果你对于题目理解有问题，欢迎加入嵌入式工作室招新qq群提出问题，群里有学长学姐耐心解答你的疑惑，帮你启发思路．  
你可以上网参考相关代码，但是杜绝直接抄袭．我们有专门的爬虫程序和查重程序，将在谷歌百度爬取相应代码并查重，如有发现抄袭代码作弊行为，后果自负．  

提交时间：2017-12-1 23：59  

提交邮箱：fyxformal@163.com

提交格式：zip压缩文件

提交文件的命名方式:嵌入式工作室第二期题目-姓名.zip

# 第四章 复合类型

## 4.6 枚举

`enum`语句提供了另一种创建符号常量的方式，可以暂时代替`const`，并定义了新类型，例如：

```c++
enum spectrum {red,orange,yellow,green,blue,violet,indigo,ultraviolet};
```

它完成了两项工作：

- 让`spectrum`成为新类型的名称，即枚举（`enumeration`）。
- 将`red`,`orange`,`yellow`等作为符号常量，对应整数值0~7。



可以声明这种类型的变量：

```c++
spectrum band;
```

它有几种特性：

- 在不进行强制类型转换时，只能用定义枚举时使用的枚举量给它赋值：

```c++
band=blue;//允许
band=2000;//不允许
```

- 对于枚举，只定义了赋值运算符，也就是没有定义算术运算：

```c++
band=orange;//允许
++band;//不允许
band=orange+red;//不允许
```

- 枚举量是整型，可被提升为int类型，但int类型不能自动转换为枚举类型：

```c++
int color=blue;//允许，枚举量被提升为int类型
band=3;//不允许，int类型不能提升为枚举类型
color=3+red;//允许，red被提升为int类型
```

- 如果int值是有效的，则可以通过强制类型转换，将它赋给枚举变量：

```c++
band=spectrum(3);
```

如果试图对一个不适当的值进行强制类型转换，不会出错，但结果将是不确定的：

```c++
band=spectrum(40003);//结果不确定
```



枚举更常被用于定义相关的符号常量，而不是新类型，可以用于`switch`语句，枚举类型的名称可以省略：

```c++
enum {red,orange,yellow,green,blue,violet,indigo,ultraviolet};
```



### 4.6.1 设置枚举量的值

- 可以用赋值运算符来显式地设置枚举量的值，但指定的值必须为整数：

```c++
enum bits {one=1,two=2,four=4,eight=8};
```

- 可以只显式地定义其中一些枚举量的值：

```c++
enum bigstep {first,second=100,third};
```

这种情况下，`first`默认为0。后面没有被初始化的枚举量将比前面的枚举量大1。因此，`third`的值为101。

- 可以创建多个值相同的枚举量：

```c++
enum {zero,null=0,one,numero_uno=1};
```

在这里，`zero`和`null`都为0，`one`和`numero_uno`都为1。现在可以将`long`和`long long`类型赋给枚举量。



### 4.6.2 枚举的取值范围

最初，对于枚举来说，只有声明中指出的那些值是有效的。但是现在的c++通过强制类型转换，可以将取值范围中的任何整数赋给枚举变量，即使这个值不是枚举值：

```c++
enum bits {one=1,two=2,four=4,eight=8};
bits myflag;
myflag=bits(6);//有效，因为6在取值范围内
```

取值范围的定义如下：

1. 找到枚举量的最大值。
2. 找到大于这个最大值的、最小的2的幂，将它减去1，得到上限。
3. 找到枚举量的最小值。
4. 如果最小值不小于0，则下限为0。
5. 如果最小值小于0，则找到小于这个最小值，最大的2的幂（冠上负号），再加一：加入最小值为-6，则下限为-8。



# 第十章 对象和类

## 10.2 抽象和类

### 10.2.3 实现类成员函数

#### 2. 内联方法

定义位于类声明中的函数都将自动成为内联函数：

```c++
class Stock{
private:
    ...
    void set_tot(){
        ...
    }
}
```

或者采用显式声明的方法：

```c++
class Stock{
private:
    ...
    void set_tot();
}
inline void Stock::set_tot(){
    ...
}
```

最可行，最简便的方法是：将内联定义放在定义类的头文件中。



## 10.3 类的构造函数和析构函数

### 10.3.1 声明和定义构造函数

构造函数名称与类名相同，没有声明类型，也没有返回值，位于public中，也可以使用默认参数：

```c++
class Stock{
private:
    ...
public:
    Stock(const string& co,long n=0,double pr=0.0);
    ...
}
//定义构造函数
Stock::Stock(const string& co,long n=0,double pr=0.0){
    ...
}
```

程序声明对象时，将自动调用构造函数。



不要将类成员名称用作构造函数的参数名，如下所示：

```c++
Stock::Stock(const string& company,long shares,double share_val){
    shares=shares;
    ...
}
```

这种混乱将导致赋值失败，有两种常用的做法：

1.在数据成员中使用m_前缀：

```c++
class Stock{
private:
    string m_company;
    long m_shares;
    ...
}
```

2.在成员名中使用后缀_：

```c++
class Stock{
private:
    string company_;
    long shares_;
    ...
}
```



### 10.3.2 使用构造函数

c++有两种使用构造函数的方式，第一种是显式调用：

```c++
Stock food=Stock("World Cabbage",250,1.25);
```

另一种是隐式调用：

```c++
Stock food("World Cabbage",250,1.25);
```



将构造函数与new一起使用：

```c++
Stock *pstock=new Stock("World Cabbage",250,1.25);
```

这条语句创建一个Stock对象，将其初始化，并把它的地址赋给pstock指针。该对象没有名称，但可以使用指针来管理它。



### 10.3.3 默认构造函数

如果没有提供任何构造函数，c++将自动提供默认构造函数，不做任何工作。但当为类定义了构造函数后，程序员就必须为它提供默认构造函数，有两种方法：
1.给已有的构造函数的所有参数提供默认值：

```c++
Stock(const string& co="Error",int n=0,double pr=0.0){
    ...
}
```

2.通过函数重载定义另一个默认构造函数：

```c++
Stock(){
    company="no name";
    ...
}
```

不要同时使用以上两种方法！



```c++
Stock first("World");//调用非默认构造函数
Stock second();//second()是一个返回Stock对象的函数
Stock third;//调用默认构造函数
```

隐式地调用默认构造函数时，不要使用圆括号。



### 10.3.4 析构函数

析构函数的名称：在类名前加上~。析构函数没有返回值和声明类型，重要的是，析构函数没有参数。如果类的构造函数使用new来分配内存，则可在析构函数中使用delete来释放它，如果没有使用new，析构函数则没有什么要完成的任务。

可以这样编写：

```c++
Stock::~Stock(){
    std::cout<<"Bye!\n";
}
```

一般由编译器决定什么时候调用析构函数，通常不应在代码中显示地调用析构函数。

如果没有提供析构函数，编译器将隐式地声明一个默认析构函数。

析构函数只能有一个。



### 10.3.5 改进Stock类

#### 4. 程序说明

c++允许使用两种方式来执行：

```c++
Stock stock2=Stock("Boffo Objects",2,2.0);
```

第一种是创建stock2对象，并将其初始化。

第二种是创建一个临时对象，然后将该临时对象复制到stock2中，并丢弃它，何时丢弃取决于编译器。

如果已经存在stock2对象：

```c++
Stock stock2;
stock2=Stock("Boffo Objects",2,2.0);
```

这种赋值语句总会创建一个临时对象，然后丢弃它，何时丢弃取决于编译器。



#### 5. c++11列表初始化

只要提供与某个构造函数的参数列表匹配的内容，并用大括号将他们括起，便可列表初始化类对象：

```c++
Stock hot_tip={"a",100,45.0};
Stock jock {"b"};
Stock temp {};
```



#### 6. const成员函数

```c++
const Stock land=Stock("a");
land.show();
```

对于当前的c++来说，第二行将被拒绝。因为show()的代码无法确保对象不被修改，解决方法是把`const`关键字放在函数的括号后面：

```c++
void show() const;//保证不会修改数据成员
void Stock::show() const;//在类外定义时
```

只要类方法不修改调用对象，就应将其声明为const。



## 10.4 this指针

```c++
class Stock{
private:
    double total_val;
    ...
public:
    double total() const {return total_val;}
    ...
};
```

设计一个成员函数，比较两个Stock对象哪个total_val较大：

```c++
const Stock& Stock::topval(const Stock& s) const{
    if(s.total_val>total_val){
        return s;
    }
    else{
        return *this;
    }
}
```

括号中的`const`表明，该函数不会修改被显式访问的对象；而括号后的`const`表明，该函数不会修改被隐式访问的对象。应为函数返回两个`const`对象之一的引用，所以返回值为`const`引用。



每个成员函数（包括构造函数和析构函数）都有一个this指针。this指针指向调用对象。如果方法需要引用整个调用对象，则可以使用表达式`*this`。在函数的括号后面使用`const`限定符，将不能使用`this`来修改对象的值。



## 10.5 对象数组

声明对象数组的方法与声明标准类型数组相同：

`Stock mystuff[4];`

每个元素（`mystuff[0]`，`mystuff[1]`）都是Stock对象，都可以使用Stock方法：

```c++
mystuff[0].update();
mystuff[3].show();
const Stock* tops=mystuff[2].topval(mystuff[1]);
```



可以用构造函数来初始化数组元素。此时必须为每个元素调用构造函数：

```c++
const int STKS=4;
Stock stocks[STKS]={
    Stock("a",12.5,20),
    Stock("b",200,2.0),
    Stock("c",130,3.25),
    Stock("d",60,6.5)
};
```



如果是如下情况：

```c++
const int STKS=10;
Stock stocks[STKS]={
    Stock("a",12.5,20),
    Stock(),
    Stock("b",130,3.25),
};
```

上述代码使用自定义构造函数初始化`stocks[0]`和`stocks[2]`，使用构造函数初始化`stocks[1]`。由于该声明只初始化了数组的部分元素，剩下的7个元素将调用默认构造函数初始化。



## 10.6 类作用域

在类中定义的名称（如类数据成员和类成员函数名）的作用域都为整个类，作用域为整个类的名称只在该类中是已知的，在类外是不可知的。



### 10.6.1 作用域为类的常量

有时候，使符号常量的作用域为类很有用。但以下代码不可行：

```c++
class Bakery{
private:
    const int Months=12;
    double costs[Months];
    ...
}
```

这是因为声明类只是描述了对象的形式，并没有创建对象。因此在创建对象前，没有用于存储值的空间。

有两种解决方案：

1.在类中声明一个枚举：

```c++
class Bakery{
private:
    enum{Months=12};
    double costs[Months];
    ...
}
```

注意，用这种方式声明枚举并不会创建类数据成员。另外，Months只是一个符号名称，在作用域为类的代码中遇到它时，编译器将用30来替换它（类似于`#define`？）。

2.使用关键字`static`：

```c++
class Bakery{
private:
    static const int Months=12;
    double costs[Months];
    ...
}
```

这种方式将创建一个名为Months的常量，该常量将与其他静态变量存储在一起，而不是存储在对象中。



### 10.6.2 作用域内枚举（c++11）

在传统的枚举中，两个枚举定义中的枚举量可能发生冲突：

```c++
enum egg {Small,Medium,Large,Jumbo};
enum t_shirt {Small,Medium,Large,Xlarge};
```

这将无法通过编译，因为egg Small和t_shirt Small位于相同的作用域内，将会发生冲突，解决方案如下：

```c++
enum class egg {Small,Medium,Large,Jumbo};
enum class t_shirt {Small,Medium,Large,Xlarge};
```

也可使用`struct`来代替`class`。

无论采用哪种方式，都需要使用枚举名来限定枚举量：

```c++
egg choice=egg::Large;
t_shirt Floyd=t_shirt::Large;
```



常规枚举将自动转换为整型，但作用域内枚举不能隐式转换为整型：

```c++
enum egg_old {Small,Medium,Large,Jumbo};//常规枚举
enum class t_shirt {Small,Medium,Large,Xlarge};//作用域内枚举

egg_old one=Medium;
t_shirt rolf=t_shirt::Large;
int king=one;//常规枚举隐式转换
int ring=rolf;//不允许，作用域内枚举不能隐式转换
if(king<Jumbo){...}//允许
if(king<t_shirt::Medium){...}//不允许
```

必要时可进行显式转换：

```c++
int Frodo=int(t_shirt::Small);
```



可以指定底层类型：

```c++
enum class:short pizza{Small,Medium,Large,Xlarge};
```

`:short`将底层类型指定为`short`，底层类型必须为整型。



## 10.7 抽象数据类型

`ADT`（抽象数据类型）以通用的方式描述数据类型，而没有引入语言或实现细节，例如栈。

栈有如下行为：

- 可创建空栈
- 可将数据项添加到栈顶（压入）。
- 可从栈顶删除数据项（弹出）。
- 可查看栈是否填满。
- 可查看栈是否为空。

详细实现请参考c++ primer 类 课本示例。



# 第十一章 使用类

## 11.1 运算符重载

要重载运算符，需使用被称为运算符函数的特殊函数形式。其格式如下：

```c++
operator op(argument-list)
```

例如，`operator +()`重载`+`运算符，`operator *()`重载`*`运算符。op必须是有效的c++运算符，而不能虚构一个新的符号。



来看一个普通函数的代码：

```c++
Time Time::Sum(const Time& t)const{
    Time sum;
    ...
    return sum;
}
```

将参数声明为引用是为了提高效率。然而，返回值不能是引用。因为函数将创建一个新的Time对象。若返回对象将创建对象的副本，而调用函数可以使用它。若返回类型为`Time &`，则引用的将是`sum`对象，由于`sum`对象是局部变量，在函数结束时将删除，因此引用将指向一个不存在的对象。



### 11.2.1 添加加法运算符

要将上节的`Sum`函数转换为重载的加法运算符，只需将`Sum()`的名称改为`operator +()`即可：

```c++
Time Time::operator +(const Time& t)const{
    Time sum;
    ...
    return sum;
}
```

和`Sum()`一样，`operator +()`也是由`Time`对象调用的，它将第二个`Time`对象作为参数，并返回一个`Time`对象。因此可以像调用`Sum()`那样来调用`operator +()`方法：

```c++
total=coding.operator+(fixing);
```

但也可以使用运算符表示法：

```c++
total=coding+fixing;
```



总之，`operator +()`函数的名称使得可以使用函数表示法或运算符表示法来调用它。编译器将根据操作数的类型来确定如何做：

```c++
int a,b,c;
Time A,B,C;
c=a+b;//使用int类型加法
C=A+B;//使用用户自定义的加法
```



重载的加法运算符可以将多个对象相加：

```c++
Time t1,t2,t3,t4;
t4=t1+t2+t3;//这是有效的
```

由于`+`是从左向右结合的运算符，因此工作机理如下：

1. 转换为：`t4=t1.operator+(t2+t3);`
2. 然后再转换为：`t4=t1.operator+(t2.operator+(t3));`
3. 函数调用`t2.operator+(t3)`返回一个`Time`对象，后者是`t2`和`t3`的和。然后，该对象成为函数调用`t1.operator+()`的参数，该调用返回`t1`与表示`t2`和`t3`之和的`Time`对象的和。



### 11.2.2 重载限制

以下为c++对用户定义的运算符重载的限制：

1. 重载后的运算符必须至少有一个操作数是用户定义的类型，这将防止用户为标准类型重载运算符。

2. 使用运算符时不能违反运算符原来的句法规则，即运算符的目数不能改变。同样，不能改变运算符的优先级。

3. 不能创建新运算符。

4. 下面的运算符只能通过成员函数进行重载：

   - `=`：赋值运算符
   - `()`：函数调用运算符
   - `[]`：下标运算符
   - `->`：通过指针访问类成员的运算符

5. 不能重载以下运算符：

   - `sizeof`：`sizeof()`运算符
   - `.`：成员运算符
   - `.*`：成员指针运算符
   - `::`：作用域解析运算符
   - `?:`：条件运算符
   - `typeid`：一个`RTTI`运算符
   - `const_cast`：强制类型转换运算符
   - `dynamic_cast`：强制类型转换运算符
   - `reinterpret_cast`：强制类型转换运算符
   - `static_cast`：强制类型转换运算符

   

## 11.3 友元

友元有如下三种：

- 友元函数
- 友元类
- 友元成员函数

通过让函数成为类的友元，可以赋予该函数与类的成员函数相同的访问权限。



让我们来看看为什么需要友元函数吧！如下面的语句：

`A=B*2.75;`

将被转换为下面的成员函数调用：

`A=B.operator*(2.75);`

但是如下的语句：

`A=2.75*B;`

从概念上说，`2.75*B`应该与`B*2.75`相同，但第一个表达式不对应于成员函数，因为`2.75`不是`Time`类型的对象。左侧的操作数应是调用对象，但`2.75`不是对象。因此，编译器不能使用成员函数调用来替换该表达式。



利用非成员函数可以将表达式：

`A=2.75*B;`

与下面的非成员函数调用匹配：

`A=operator*(2.75,B);`

该函数的原型如下：

`Time operator*(double m,const Time&t);`

再将其设置为友元函数，便可访问类对象的私有成员。



### 11.3.1 创建友元

1. 创建友元函数的第一步是将其原型放在类声明中，并在原型声明前加上关键字`friend`：`friend Time operator*(double m,const Time& t);//在类中声明`

   该原型意味着以下两点：

   - 虽然`operator*()`是在类声明中声明的，但它不是成员函数，不能通过成员运算符来调用
   - 虽然`operator*()`不是成员函数，但它与成员函数的访问权限相同

2. 第二步是编写函数定义。因为它不是成员函数，所以不要使用`Time::`限定符。另外，不要在定义中使用关键字`friend`，定义应该如下：

   ```c++
   Time operator*(double m,const Time&t){
       ...
   }
   ```

总之，类的友元函数是非成员函数，其访问权限与成员函数相同。



### 11.3.2 常用的友元：重载<<运算符

类可以重载`<<`运算符，使之能与`cout`一起来显示对象的内容。然而这种重载需要分两步来完成。



最初，`<<`运算符是位运算符，将值中的位左移。`ostream`类对该运算符进行了重载，将其转换为一个输出工具。`cout`是一个`ostream`对象，能够识别所有的c++基本类型。修改`iostream`文件很危险，应该通过`Time`类声明来让`Time`类知道如何使用`cout`。



#### 1. <<的第一种重载版本

要使`Time`类知道使用`cout`，必须使用友元函数。如果使用一个`Time`成员函数来重载`<<`，`Time`对象将是第一个操作数，意味着必须这样使用`<<`：

`trip<<cout;`

但通过使用友元函数，可以按如下重载`<<`运算符：

```c++
void operator<<(ostream&os,const Time&t){
    os<<t.hours<<" hours, "<<t.times<<" minutes";
}
```

则可以使用如下的语句：

`cout<<trip`

按如下格式打印数据：

`4 hours, 23 minutes`



有以下注意点：

- `operator<<()`直接访问`Time`对象的私有成员，所以它必须是`Time`类的友元；但由于它并不直接访问`ostream`对象的私有成员，所以并不一定必须是`ostream`的友元。
- 其他的`ostream`对象是`cerr`，它将输出发送到标准输出流——默认为显示器。通过继承，`ofstream`对象可以使用`ostream`对象的方法。
- 调用`cout<<trio`应使用`cout`对象本身，而不是其拷贝，因此该函数按引用来传递该对象。



#### 2. <<的第二种重载版本

之前的实现存在一个问题。像如下的语句可以正常工作：

`cout<<trip;`

但如下的语句不可行：

`cout<<"Trip time:"<<trip<<...;`



需要了解`cout`操作的原理。请看如下语句：

```c++
int x=5;
int y=8;
cout<<x<<y;
```

c++从左向右读取语句，它等同于：

`(cout<<x)<<y;`

`<<`运算符要求左边是一个`ostream`对象。因为`cout`是`ostream`对象，所以表达式`cout<<x`满足这种要求。然而，因为`cout<<x`位于`<<y`的左侧，所以输出语句也要求该表达式是一个`ostream`类型的对象。因此，`ostream`类将`operator<<()`函数实现为返回一个指向`ostream`对象的引用。



因此，只要修改`operator<<()`函数，让其返回`ostream&`即可：

```c++
ostream& operator<<(ostream&os,const Time&t){
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
    return os;
}
```

注意，返回类型为：`ostream &`



## 11.4 重载运算符：作为成员函数还是非成员函数

一般来说，非成员函数应是友元函数，这样它才能直接访问类的私有数据。例如之前重载的`+`运算符：

`Time operator+(const Time&t)const;`

也可以使用友元函数的原型：

`friend Time operator+(const Time&t1,const Time&t2);`

`+`运算符需要两个操作数。对于成员函数版本来说，一个操作数通过`this`指针隐式地传递，另一个操作数作为函数参数显式地传递；对于友元版本来说，两个操作数都作为参数来传递。



有以下注意点：

- 在定义运算符时，必须选择其中的一种格式，而不能同时选择这两种格式，不然会导致二义性。
- 对于某些运算符来说，成员函数是唯一合法的选择。在其他情况下，这两种格式没有太大的区别。有时，根据类设计，使用非成员函数版本可能更好。



## 11.5 再谈重载：一个矢量类

详情见课本示例，这是总量大复习。



### 11.5.2 为Vector类重载算数运算符

将两个矢量相加可能会使用如下的代码：

```c++
Vector Vector::operator+(const Vector&b)const{
    Vector sum;
    sum.x=x+b.x;
    sum.y=y+b.y;
    return sum;
}
```

如果对象只储存`x`和`y`分量，则这很好，但是上述代码无法设置极坐标值。可以再添加一些代码来解决问题：

```c++
Vector Vector::operator+(const Vector&b)const{
 	Vector sum;
    sum.x=x+b.x;
    sum.y=y+b.y;
    sum.set_ang(sum.x,sum.y);
    sum.set_ang(sum.x,sum.y);
    return sum;
}
```

然而，使用构造函数来完成该工作，将更简单、更可靠：

```c++
Vector Vector::operator+(const Vector&b)const{
    return Vector(x+b.x,y+b.y);
}
```

这种方法确保了新的`Vector`对象是根据构造函数指定的标准规则创建的。



#### 2. 对已重载的运算符进行重载

在c++中，`-`运算符有两种含义。首先，使用两个操作数，它是减法运算符。其次使用一个操作数时（如-x），它是负号运算符。

可以定义`-`运算符的一元和二元版本，因为c++提供了该运算符的一元和二元版本。对于只有二元形式的运算符，则只能将其重载为二元运算符。

注意：

- 因为运算符重载是通过函数来实现的，所以只要运算符函数的特征标不同，使用的运算符数量与相应的内置c++运算符相同，就可以多次重载同一个运算符。



### 11.5.4 使用Vector类来模拟随机漫步

具体实现请参照课本示例。



我们来谈谈随机数。c++有一个`rand()`函数，它返回一个从0到某个值之间的随机整数。`rand()`函数将一种算法用于一个初始种子值来获得随机数，该随机值将用作下一次函数调用的种子。这些数实际上是伪随机数，因为十次连续的调用通常将生成十个同样的随机数。

然而`srand()`函数允许覆盖默认的种子值，重新启动另一个随机数序列。该程序使用`time(0)`的返回值来设置种子。`time(0)`函数返回当前时间，因而每次运行时都将设置不同的种子：

`srand(time(0));`

头文件`cstdlib`包含了`srand()`和`rand()`函数的原型，而`ctime`提供了`time()`的原型。头文件`random`提供了更强大的随机数支持。



第二点是，将一系列位置存储到文件中很容易。首先包含头文件`fstream`，声明一个`ofstream`对象，将其同一个文件关联起来：

```c++
#include<fstream>
...
ofstream fout;
fout.open("thewalk.txt");
```

然后，在计算结果的循环中加入类似下面的代码：

`fout<<result<<endl;`

这将调用友元函数`operator<<(fout,result)`，因为基类引用可以指向派生类对象，因此可以将输出写入到文件中。



## 11.6 类的自动转换和强制类型转换

将一个标准类型变量的值赋给另一种标准类型的变量时，如果这两种类型兼容，则c++自动将这个值转换为接受变量的类型：

```c++
long count=8;//int类型值8转换为long类型
double time=11;//int类型值11转换为double类型
int side=3.3;//double类型值3.3转换为int类型
```



c++不自动转换不兼容的类型。例如，下面的语句是非法的，因为左边为指针类型，右边为数字：

`int *p=10;`

在无法自动转换时，可以使用强制类型转换：

`int *p=(int *)10;`

上述语句将10强制转换为`int *`类型，并把指针设置为地址10，然而这没有意义。



可以将类定义成与基本类型或与另一个类相关，使得从一种类型转换为另一种类型是有意义的。程序员可以指示c++如何自动进行转换，或者通过强制类型转换完成。详情见课本示例。



> 类的自动转换

在c++中，接受一个参数的构造函数为将类型与该参数相同的值转换提供了蓝图。因此，下面的构造函数用于将`double`类型的值转换为`Stonewt`类型：

`Stonewt(double lbs);`

也就是说，可以编写这样的代码：

```c++
Stonewt myCat;
myCat=19.6;
```

程序将使用构造函数`Stonewt(double)`来创建一个临时的`Stonewt`对象，并将`19.6`作为初始化值。随后，采用逐成员赋值方式将该临时对象的内容复制到`myCat`中，这一过程称为隐式转换。



只有接受一个参数的构造函数才能作为转换函数。下面的构造函数有两个参数，因此不能用来转换类型：

`Stonewt(int stn,double lbs);`

然而，如果给第二个参数提供默认值，它便可以用于转换`int`：

`Stonewt(int stn,double lbs=0);`



将构造函数用作自动类型转换确实不错，但是有可能导致意外的类型转换。因此，c++新增了关键字`explicit`，用于关闭这种自动特性。也就是这样：

`explicit Stonewt(double lbs);//只能允许显式转换`

这将关闭隐式转换特性，但仍然允许显式转换：

```c++
Stone myCat;
myCat=19.6;//如果使用了explicit，则不允许
myCat=Stone(19.6);//显式转换
myCat=(Stonewt)19.6;//老版本的显式转换
```



如果在声明中使用了关键字`explicit`，则`Stonewt(double)`将只用于显式强制类型转换，否则还可以用于以下的隐式转换：

- 将`Stonewt`对象初始化为`double`值时。
- 将`double`值赋给`Stonewt`对象时。
- 将`double`值传递给接受`Stonewt`参数的函数时。
- 返回值被声明为`Stonewt`的函数试图返回`double`值时。
- 在上述任意一种情况下，使用可以转换为`double`类型的内置类型时。



c++允许函数原型化提供的参数匹配过程，允许使用`Stonewt(double)`构造函数来转换其他数值类型。也就是说，下面两条语句都首先将`int`转换为`double`，然后使用`Stonewt(double)`构造函数：

```c++
Stonewt Jumbo(7000);
Jumbo=7300;
```

然而，只有不存在二义性时，才会进行这种二步转换。也就是说，如果这个类还定义了构造函数`Stonewt(long)`，则编译器将拒绝这些语句，因为存在二义性。



> 程序说明

当构造函数只接受一个参数时，可以使用如下格式来初始化类对象：

`Stonewt incognito=275;`

这等价于前面介绍过的另外两种格式：

```c++
Stonewt incognito(275);
Stonewt incognito=Stonewt(275);
```



请注意以下两条赋值语句：

```c++
incognito=276.8;
taft=325;
```

第一条赋值语句使用接受`double`参数的构造函数，将`276.8`转换为一个`Stonewt`值，这将把`incognito`的`pound`成员设置为`276.8`。因为该语句使用了构造函数，所以还将设置`stone`和`pds_left`成员。同样，第二条赋值语句先将`int`值转换为`double`类型，然后再使用构造函数。



最后请注意以下函数调用：

```c++
void display(const Stonewt&wt,int n){
    ...
}
display(422,2);
```

`display()`函数的第一个参数应该为`Stonewt`对象，当遇到`int`参数时，编译器将查找构造函数`Stonewt(int)`，由于没有找到这样的构造函数，因此编译器寻找接受其他内置类型（`int`可以转换为该类型）的构造函数。`Stonewt(double)`构造函数满足了这种要求。



### 11.6.1 转换函数

我们使用构造函数将数字转换为`Stonewt`对象，那么，能否可以将`Stonewt`对象转换为`double`值，就如下面所示？

```c++
Stonewt wolfe(285.7);
double host=wolfe;
```

可以这样做，但是不使用构造函数，使用特殊的c++运算符函数——转换函数。



转换函数是用户定义的强制类型转换，假如已经定义，则可使用如下转换：

```c++
Stonewt wolfe(285.7);
double host=double(wolfe);//显式调用
double thinker=(double)wolfe;//显式调用
double star=wells;//隐式调用
```



> 转换函数

要转换为`typename`类型，需要使用这种形式：

`operator typename();`

有以下注意点：

- 转换函数必须是类方法。
- 转换函数不能指定返回类型。
- 转换函数不能有参数。

例如，转换为`double`类型的函数原型如下：

`operator double();`

`typename`指出了要转换成的类型，因此无需返回类型。转换函数是类方法意味着，它需要通过类对象来调用，从而告知函数需要转换的值。因此，函数无需参数。



在同时拥有多个转换函数时，如果没有明确的信息指出应转换为什么类型，将导致二义性。然而，当只定义了一个转换函数时，因为只有一种转换可能，将被接受。

例如，对拥有`int`和`double`转换函数的类而言，以下语句不可行：

`long gone=poppins;`

因为`int`和`double`都可以被赋值给`long`变量，将导致二义性。如果只有一个转换函数，将可行。



可以使用显式强制类型转换来制定要使用哪个转换函数。如下：

```c++
long gone=(double)poppins;
long gone=int(poppins);
```



提供自动、隐式转换的函数所存在的问题是：在用户不希望进行转换时，转换函数也可能进行了转换：

```c++
int ar[20];
...
Stonewt temp(14,4);
...
int Temp=1;
...
cout<<ar[temp]<<...;
```

由于`Stonewt`类提供了`operator int()`，因此`Stonewt`对象`temp`将被转换为`int 200`，并用作数组索引。原则上说，最好使用显式转换，避免隐式转换。在c++11中，可以将转换函数声明为显式的：

```c++
class Stonewt{
    ...
    explicit operator int()const;
    explicit operator double()const;
};
```



总之，有如下注意点：

- 只有一个参数的类构造函数用于将与该参数相同的值转换为类类型。可以在构造函数声明中使用`explicit`防止隐式转换，只允许显式转换。
- 转换函数是类成员，没有返回类型、没有参数、名为`operator typename()`。



### 11.6.2 转换函数和友元函数

我们指出过，可以使用成员函数或友元函数来重载加法。可以提供上述的一种定义，但不能两者都提供，来看一个例子（已经提供了`Stonewt(double)`转换函数）：

```c++
Stonewt jennySt(9,12);
double kenntD=176.0;
Stonewt total;
total=jennyst+kennyD;//类+double
total=kenny+jenny;//double+类
```

1. 对于第一种情况，成员函数和友元函数都可以实现。
2. 对于第二种情况，如果只有成员函数的定义，则程序不会将`double`类型转换为`Stonewt`类型，而会尝试将`Stonewt`类型转换为`double`类型，然而过多的转换函数容易导致二义性（建议显式转换）。



定义加法的选择：

使用友元函数（定义了将`double`类型转换为`Stonewt`类型的构造函数）：

`operator+(const Stonewt&,const Stonest&);`

使用成员函数和一个显式定义与`double`的加法：

```c++
Stonewt operator+(double x);
friend Stonewt operator+(double x,Stonewt&s);
```

两种方式都各有其优缺点。



# 第十二章 类和动态内存分配

## 12.1 动态内存和类

### 12.1.1 复习示例和静态类成员

#### 1.静态类成员

```c++
//头文件
class A{
private:
    static int a;
    ...
}

//cpp文件
int A::a=0;
```

有以下注意点：

1. 不能在类声明中初始化静态成员变量，这是因为声明描述了如何分配内存，但并不分配内存。
2. 无论创建了多少对象，程序都只创建一个静态类变量副本。也就是说，类的所有对象共享一个静态成员。
3. 可以在类声明之外使用单独语句来初始化静态类变量，请注意：
   - 初始化语句指出了类型`int`，并使用了域作用符`::`，但没有使用关键字`static`。
   - 初始化是在cpp文件中，而不是在头文件中。如果把静态类成员初始化在头文件中，程序可能将头文件包含在其他几个cpp文件中，这将造成重复声明。



#### 2. 在类中使用new运算符

假如有以下类声明以及实现：

```c++
//头文件
class A{
private:
    char*p;
public:
    A();
    ~A();
    ...
}

//cpp文件
A::A(){
    p=new char;
    ...
}
A::~A(){
    ...
	delete p;
}
```

请注意以下几点：

- 当`A`对象过期时，其指针`p`也将过期，但是`p`指向的内存仍被分配，除非使用`delete`将其释放。删除对象可以释放`A`对象本身占用的内存，但并不能自动释放属于`A`对象成员的指针指向的内存，因此必须显式定义析构函数。
- 注意`delete`和`new`配对，`delete[]`和`new`配对。



### 12.1.2 特殊成员函数

如果以下成员函数没有被显式定义，c++将自动定义：

- 默认构造函数
- 默认析构函数
- 复制构造函数
- 赋值运算符
- 地址运算符

隐式地址运算符返回调用对象的地址（即`this`指针的值），这与我们的初衷相一致。



#### 1. 复制构造函数

复制构造函数用于将一个对象复制到新创建的对象中，它的原型通常如下：

`Class_name(const Class_name&);`

它接受一个指向类对象的常量引用作为参数。对于复制构造函数，需要知道何时调用以及有何种功能。

##### 1. 何时调用复制构造函数

新建一个对象并将其初始化为同类的现有对象时，复制构造函数都将被调用，最常见的情况是将新对象显式地初始化为现有的对象，如一下四种声明都将调用复制构造函数：

```
string ditto(motto);
string ditto=motto;
string ditto=string(motto);
string *ditto=new string(motto);
```

补充情况：当程序生成了对象副本时，编译器都将调用复制构造函数。比如按值传递以及返回一个对象。

##### 2. 默认的复制构造函数的功能

默认的复制构造函数逐个复制非静态成员（也称作浅复制）。静态成员不受影响，因为他们属于整个类，而不是各个对象。



### 12.1.3 回顾默认复制构造函数哪里出了问题

1. 默认复制构造函数不会操作静态数据成员，如果类中包含这样的静态数据成员，其值在新对象被创建时发生变化，则应该提供一个显式复制构造函数来处理计数问题。
2. 隐式复制构造函数是按值进行复制的，也就是说，如果类有某个指针，则会将指针的值复制，造成两个指针指向同一块内存。



### 12.1.4 重载赋值运算符

c++允许类对象赋值，这是通过自动为类重载赋值运算符`=`实现的，其原型如下：

`class_name& class_name::operator=(const class_name&);`

它接受并返回一个指向类对象的引用。

#### 1. 赋值运算符的功能以及何时使用它

将已有的对象赋给另一个对象时，将使用重载的赋值运算符：

```c++
string s1("aaa");
...
string s2;
s2=s1;
```

初始化对象时，并不一定会使用赋值运算符：

`string s2=s1;`

与复制构造函数相似，赋值运算符的隐式实现也对成员进行逐个复制。

#### 2. 解决赋值的问题

提供赋值运算符的显示定义与实现复制构造函数相似，但有一些差别：

- 由于目标对象可能引用了以前分配的数据，所以函数应先使用`delete[]`来释放掉这些数据。
- 函数应当避免将对象赋给自身；否则，给对象重新赋值前，释放内存操作可能删除对象的内容。
- 函数应返回一个指向调用对象的引用。



# 第十三章 类继承

可以通过类继承完成以下工作：

- 可以在已有类的基础上添加功能。例如，对于数组类，可以添加数学运算。
- 可以给类添加数据。例如，对于字符串类，可以派生出一个类，并添加指定字符串显示颜色的数据成员。
- 可以修改类方法的行为。例如，对于代表提供给飞机乘客的服务的`Passenger`类。可以派生出提供更高级别服务的`FirstClassPassenger`类。

实际上也可以通过复制原始类代码，对其进行修改来完成上述工作。但类继承机制只需提供新特性，甚至不需要访问源代码就可以派生出类。



## 13.1 一个简单的基类

从一个类派生出另一个类时，原始类称为基类，继承类称为派生类。



### 13.1.1 派生一个类

将`RatedPlayer`类声明为从`TableTennisClass`类派生而来：

```c++
class RatedPlayer:public TableTennisClass{
    ...
};
```

冒号指出`RatedPlayer`类的基类是`TableTennisPlayer`类，`public`表示公有派生。使用公有派生后：派生类对象包含基类对象；基类的公有成员将成为派生类的公有成员；基类的私有部分也将成为派生类的一部分，但只能通过基类的公有和保护方法访问。

上述代码完成的工作有：

- 派生类对象存储了基类的数据成员（派生类继承了基类的实现）。
- 派生类对象可以使用基类的方法（派生类继承了基类的接口）。



提出了一个问题：需要在继承特性中添加什么呢？

- 派生类需要自己的构造函数。
- 派生类可以根据需要添加额外的数据成员和成员函数。

在这个例子中，派生类需要另一个数据成员来存储比分，还应包含检索比分的方法和重置比分的方法，类声明与以下类似：

```c++
class RatedPlayer:public TableTennisPlayer{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r=0,const string& fn="none",const string& ln="none",bool ht=false);
    RatedPlayer(unsigned int r,const TableTennisPlayer&tp);
    unsigned int Rating()const{return rating;}
    void ResetRating(unsigned int r){rating=r;}
};
```

构造函数必须给新成员（如果有的话）和继承的成员提供数据。



### 13.1.2 构造函数：访问权限的考虑

由于派生类不能直接访问基类的私有成员，而必须通过基类方法进行访问。例如，`RatedPlayer`构造函数不能直接设置继承的成员（`firstname`，`lastname`和`hasTable`），而必须使用基类的公有方法来访问私有的基类成员。具体地说，派生类构造函数必须使用基类构造函数。

创建派生类对象时，程序首先创建基类对象。从概念上说，这意味着基类对象应当在程序进入派生类构造函数之前被创建。`C++`使用成员初始化列表语法来完成这项工作，如下：

```c++
RatedPlayer::RatedPlayer(unsigned int r,const string&fn,const string&ln,bool ht):TableTennisPlayer(fn,ln,ht){
    rating=r;
}
```

其中，`:TableTennisPlayer(fn,ln,ht)`是成员初始化列表。它是可执行的代码，调用`TableTennisPlayer`构造函数。

假如程序包含如下声明：

```c++
RatedPlayer rplayer1(1140,"Mallory","Duck",true);
```

则`RatedPlayer`构造函数将把实参`"Mallory"`，`"Duck"`和`true`赋给形参`fn`，`ln`和`ht`，然后将这些参数作为实参传递给`TableTennisPlayer`构造函数，后者将创建一个嵌套的`TableTennisPlayer`对象，并将数据`"Mallory"`，`"Duck"`和`true`存储在该对象中。然后，程序进入`RatedPlayer`构造函数体，完成`RatedPlayer`对象的创建，并将`r`的值赋给`rating`成员。



如果省略成员初始化列表：

```c++
RatedPlayer::RatedPlayer(unsigned int r,const string&fn,const string&ln,bool ht){
    rating=r;
}
```

因为必须首先创造基类对象，如果不调用基类构造函数，程序将使用默认的基类构造函数。除非要使用默认的构造函数，否则应显式调用正确的基类构造函数。



下面看看另一种方式：

```c++
RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer&tp):TableTennisPlayer(tp){
    ratint=r;
}
```

这种方式将调用基类的复制构造函数（如果没有定义复制构造函数，编译器将自动生成一个，在没有使用`new`的情况下，这是合适的）。



如果愿意，也可以对派生类成员使用成员初始化列表：

```c++
RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer&tp):TableTennisPlayer(tp),rating(r){
    ...
}
```



总之，派生类构造函数有以下要点：

- 首先创建基类对象。
- 派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数。
- 派生类构造函数应初始化派生类新增的数据成员。

其中，释放对象的顺序与创建对象的顺序相反，即先执行派生类的析构函数，然后自动调用基类的析构函数。



### 13.1.3 使用派生类

要使用派生类，程序必须要能够访问基类声明。可以把两个类的声明放于同一个头文件中，也可以把每个类放在独立的头文件中。



### 13.1.4 派生类和基类的特殊关系

派生类对象可以使用基类的方法，如果该方法不是私有的：

```c++
RatedPlayer rplayer1(1140,"Mallory","Duck",true);
rplayer1.Name();
```

基类指针可以在不进行显式类型转换的情况下指向派生类对象；基类引用可以在不进行显式类型转换的情况下引用派生类对象：

```c++
RatedPlayer rplayer1(1140,"Mallory","Duck",true);
TableTennisPlayer& rt=rplayer;
TableTennisPlayer* pt=&rplayer;
rt.Name();
pt->Name();
```

然而，基类指针或引用只能用于调用基类方法，因此，不能使用`rt`或`pt`来调用派生类的`ResetRanking`方法。



通常，`C++`要求引用和指针类型与赋给的类型匹配，但这一规则对继承来说是例外。这种例外只是单向的，不可以将基类对象和地址赋给派生类引用和指针：

```c++
TableTennsiPlayer player("Betsy","Bloop",true);
RatedPlayer& rr=player;//不允许
RatedPlayer* pr=player;//不允许
```

派生类相对于基类，只会多不会少。基类的方法派生类一定有，而派生类的方法基类不一定有。



基类引用定义的函数或指针参数可用于基类对象或派生类对象。例如：
























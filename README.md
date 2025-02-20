# logic-calculator
简单的逻辑计算器，输出指定公式的真值表
支持五种基本的运算符：
| 名字  | 运算符 |
| --- | --- |
| 非   | not |
| 合取  | and |
| 析取  | or  |
| 蕴涵  | imp |
| 等值  | equ |
### 例子
输入
```cmd
not p or q
```
输出（带调试信息）
```cmd
Input an expression, use 'not' 'and' 'or' 'imp' 'equ' :not p or q
not,p,or,q,
T,1;F,0;p,0;q,0;
p q ans
0 0 1
0 1 1
1 0 0
1 1 1
```

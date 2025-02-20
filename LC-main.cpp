#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "catstr"
#include "CaF"
#include "CCT"

int main()
{
    using namespace std;
    cout << "Input an expression, use ";
    for (int i = 0; i < 5; i++)
        cout << "\'" << Operators[i] << "\' ";
    cout << ":";

    char strin[500];
    cin.getline(strin, 500);

    auto strs = cat_str(strin, strlen(strin));

    auto x_list = find_x(strs);

    for (string str : strs)
    {
        cout << str << ','; // << level_list[i] << ';';
    }
    cout << endl;
    for (xee x : x_list)
    {
        cout << x.name << ',' << x.value << ';';
    }
    cout << endl;

    if (!check_level(strs)) // 检查括号
        return 1;

    for (xee x : x_list)
    {
        if (!(x.name == "T" || x.name == "F"))
            cout << x.name << ' ';
    }
    cout << "ans" << endl;

    while (1) // 输出表格
    {
        for (xee x : x_list) // out
        {
            if (x.name == "T" || x.name == "F")
                continue;
            cout << x.value;
            for (int i = 0; i < x.name.size(); i++)
                cout << ' ';
        }
        cout << calculation(strs, x_list) << endl;
        bool isok = false;
        for (int i = x_list.size() - 1; i >= 0; i--) // 变数值
        {
            if (x_list[i].lock == true) // 不更改lock值
                continue;
            if (x_list[i].value == 0)
            {
                x_list[i].value = 1;
                isok = true;
                break;
            }
            else
                x_list[i].value = 0;
        }
        if (!isok)
            break;
    }

    return 0;
}
/*p and q and r or not p and q and r or p and not q and r or not p and not q and r*/
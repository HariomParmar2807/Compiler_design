// hariom paramr
#include <bits/stdc++.h>
using namespace std;

string s;
int lookAhead = 0;
bool T();
bool E();
bool E_();
bool T_();
bool F();
bool isvalid();
bool isValid(string s)
{

	if (!((s[0] >= 'a' && s[0] <= 'z')
		|| (s[0] >= 'A' && s[1] <= 'Z')
		|| s[0] == '_'))
		return false;

	for (int i = 1; i < s.length()-1; i++) {
		if (!((s[i] >= 'a' && s[i] <= 'z')
			|| (s[i] >= 'A' && s[i] <= 'Z')
			|| (s[i] >= '0' && s[i] <= '9')
			|| s[i] == '_'))
			return false;
	}

	return true;
}
bool E()
{
    if((isValid(s))  || s[lookAhead] == '(')
    {
        if(T() && E_())
        {
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool E_()
{
    if(s[lookAhead] == '+')
    {
        lookAhead ++;
        if(T() && E_())
            return true;
        else
            return false;
    }
    else if(s[lookAhead] == ')' || s[lookAhead] == '$')
    {
        return true;
    }
    else
        return false;
}

bool T()
{
    if(isvalid(s) || s[lookAhead] == '(')
    {
        if(F() && T_())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool T_()
{
    if(s[lookAhead] == '*')
    {
        lookAhead ++;
        if(F() && T_())
            return true;
        else
            return false;
    }
    else if(s[lookAhead] == '+' || s[lookAhead] == ')' || s[lookAhead] == '$')
    {
        return true;
    }
    else
        return false;
}

bool F()
{
    if((isValid(s)))
    {
        lookAhead ++;
        return true;
    }
    else if(s[lookAhead] == '(')
    {
        lookAhead ++;
        if(E())
        {
            if(s[lookAhead] == ')')
            {
                lookAhead ++;
                return true;
            }
            else
                return false;
        }
        return false;
    }
    return false;
}

int main()
{
    cin >> s;
    s = s + '$';
    bool ans = E();
    if(ans && lookAhead == s.length() - 1)
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}

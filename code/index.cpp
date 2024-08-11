#include <bits/stdc++.h>
using namespace std;
string trimLeadingWhitespaces(string &input)
{
    size_t startPos = input.find_first_not_of(" \t\n\r\f\v");
    if (startPos != string::npos)
    {
        return input.substr(startPos);
    }
    return "";
}
int stringToInt(string str)
{
    int result;
    istringstream iss(str);
    if (!(iss >> result))
    {
        return -1;
    }
    return result;
}
//--------------------------------Factorial TM-------------------------------------
void handleFactState0(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'B')
    {
        tape[head] = '1';
        state = 14;
    }
    else if (tape[head] == '1')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 1;
    }
}
void handleFactState1(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1' || tape[head] == 'D')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 1;
    }
    else if (tape[head] == 'B')
    {
        tape[head] = 'D';
        head--;
        state = 2;
    }
}
void handleFactState2(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1' || tape[head] == 'D')
    {
        head--;
        state = 2;
    }
    else if (tape[head] == 'A' || tape[head] == 'B')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 3;
    }
}
void handleFactState3(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        tape[head] = 'A';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 1;
    }
    else if (tape[head] == 'D')
    {
        head--;
        state = 4;
    }
}
void handleFactState4(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'A')
    {
        head--;
        state = 4;
    }
    else if (tape[head] == 'B')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 5;
    }
}
void handleFactState5(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D')
    {
        tape[head] = '1';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 13;
    }
    else if (tape[head] == 'A')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 6;
    }
}
void handleFactState6(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'A')
    {
        tape[head] = 'X';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 7;
    }
    else if (tape[head] == 'D')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 11;
    }
}
void handleFactState7(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'A')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 7;
    }
    else if (tape[head] == 'D')
    {
        tape[head] = 'Y';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 8;
    }
    else if (tape[head] == 'Z')
    {
        head--;
        state = 10;
    }
}
void handleFactState8(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D' || tape[head] == 'Z')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 8;
    }
    else if (tape[head] == 'B')
    {
        tape[head] = 'Z';
        head--;
        state = 9;
    }
}
void handleFactState9(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D' || tape[head] == 'Z')
    {
        head--;
        state = 9;
    }
    else if (tape[head] == 'Y')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 7;
    }
}
void handleFactState10(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'Y')
    {
        tape[head] = 'D';
        head--;
        state = 10;
    }
    else if (tape[head] == 'A')
    {
        head--;
        state = 10;
    }
    else if (tape[head] == 'X')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 6;
    }
}
void handleFactState11(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D' || tape[head] == 'Z')
    {
        tape[head] = 'D';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 11;
    }
    else if (tape[head] == 'B')
    {
        head--;
        state = 12;
    }
}
void handleFactState12(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D')
    {
        head--;
        state = 12;
    }
    else if (tape[head] == 'X')
    {
        tape[head] = 'A';
        head--;
        state = 12;
    }
    else if (tape[head] == 'B')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 5;
    }
}
void handleFactState13(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'D')
    {
        tape[head] = '1';
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 13;
    }
    else if (tape[head] == 'B')
    {
        state = 14;
    }
}
uint32_t mainFact(deque<char> &tape)
{
    int state = 0;
    uint32_t head = 0;
    while (state != 14)
    {
        if (state == 0)
        {
            handleFactState0(tape, head, state);
        }
        else if (state == 1)
        {
            handleFactState1(tape, head, state);
        }
        else if (state == 2)
        {
            handleFactState2(tape, head, state);
        }
        else if (state == 3)
        {
            handleFactState3(tape, head, state);
        }
        else if (state == 4)
        {
            handleFactState4(tape, head, state);
        }
        else if (state == 5)
        {
            handleFactState5(tape, head, state);
        }
        else if (state == 6)
        {
            handleFactState6(tape, head, state);
        }
        else if (state == 7)
        {
            handleFactState7(tape, head, state);
        }
        else if (state == 8)
        {
            handleFactState8(tape, head, state);
        }
        else if (state == 9)
        {
            handleFactState9(tape, head, state);
        }
        else if (state == 10)
        {
            handleFactState10(tape, head, state);
        }
        else if (state == 11)
        {
            handleFactState11(tape, head, state);
        }
        else if (state == 12)
        {
            handleFactState12(tape, head, state);
        }
        else if (state == 13)
        {
            handleFactState13(tape, head, state);
        }
    }
    return head;
}
uint32_t factorial(int n)
{
    deque<char> tape;
    uint32_t resHead, res = 0;
    for (int i = 1; i <= n; i++)
    {
        tape.push_back('1');
    }
    tape.push_back('B');
    resHead = mainFact(tape);
    resHead = resHead == 0 ? 0 : resHead - 1;
    for (uint32_t i = resHead; i >= 0 && tape[i] != 'B'; i--)
    {
        res++;
    }
    return res;
}
//-------------------------------------------------------------------------------------------------------------
//----------------------------Multiplication TM-----------------------------------------------------------------
void handleMultState0(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 1;
    }
    else if (tape[head] == '0')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 9;
    }
}
void handleMultState1(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 1;
    }
    else if (tape[head] == '0')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 2;
    }
}
void handleMultState2(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        tape[head] = 'X';
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 3;
    }
    else if (tape[head] == '0')
    {
        head--;
        state = 7;
    }
}
void handleMultState3(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 3;
    }
    else if (tape[head] == '0')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 4;
    }
}
void handleMultState4(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 4;
    }
    else if (tape[head] == 'B')
    {
        tape[head] = '1';
        head--;
        state = 5;
    }
}
void handleMultState5(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        head--;
        state = 5;
    }
    else if (tape[head] == '0')
    {
        head--;
        state = 6;
    }
}
void handleMultState6(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        head--;
        state = 6;
    }
    else if (tape[head] == 'X')
    {
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 2;
    }
}
void handleMultState7(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == 'X')
    {
        tape[head] = '1';
        head--;
        state = 7;
    }
    else if (tape[head] == '0')
    {
        head--;
        state = 8;
    }
}
void handleMultState8(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        head--;
        state = 8;
    }
    else if (tape[head] == 'B')
    {
        if (head >= tape.size() - 1)
        {
            tape.push_back('B');
        }
        head++;
        state = 0;
    }
}
void handleMultState9(deque<char> &tape, uint32_t &head, int &state)
{
    if (tape[head] == '1')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 9;
    }
    else if (tape[head] == '0')
    {
        tape[head] = 'B';
        if (head >= tape.size() - 1)
            tape.push_back('B');
        head++;
        state = 10;
    }
}
uint32_t mainMult(deque<char> &tape)
{
    int state = 0;
    uint32_t head = 0;
    while (state != 10)
    {
        if (state == 0)
        {
            handleMultState0(tape, head, state);
        }
        else if (state == 1)
        {
            handleMultState1(tape, head, state);
        }
        else if (state == 2)
        {
            handleMultState2(tape, head, state);
        }
        else if (state == 3)
        {
            handleMultState3(tape, head, state);
        }
        else if (state == 4)
        {
            handleMultState4(tape, head, state);
        }
        else if (state == 5)
        {
            handleMultState5(tape, head, state);
        }
        else if (state == 6)
        {
            handleMultState6(tape, head, state);
        }
        else if (state == 7)
        {
            handleMultState7(tape, head, state);
        }
        else if (state == 8)
        {
            handleMultState8(tape, head, state);
        }
        else if (state == 9)
        {
            handleMultState9(tape, head, state);
        }
    }
    return head;
}
uint32_t multiply(int x, int y)
{
    deque<char> tape;
    if (x == 0 || y == 0)
        return 0;
    uint32_t resHead, res = 0;
    for (int i = 1; i <= x; i++)
    {
        tape.push_back('1');
    }
    tape.push_back('0');
    for (int i = 1; i <= y; i++)
    {
        tape.push_back('1');
    }
    tape.push_back('0');
    tape.push_back('B');
    resHead = mainMult(tape);
    for (uint32_t i = resHead; i < tape.size(); i++)
    {
        if (tape[i] == '1')
        {
            res++;
        }
    }
    return res;
}
//--------------------------------------------------------------------
vector<string> splitString(string inputString, char delimiter)
{
    vector<string> result;
    stringstream ss(inputString);
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}
bool isInD(char ch)
{
    if ((int(ch) >= 48 && int(ch) <= 57))
        return true;
    return false;
}
struct Integer
{
    int a;
};
// global variables
vector<Integer> IntTable;
vector<char> delimiterSet = {'*', '!', ')', '$'};
bool isError = false;
void state0(char ch, string line, int tracer, string &buffer, auto &fout);
bool isDelimiter(char ch)
{
    for (char c : delimiterSet)
    {
        if (c == ch)
        {
            return true;
        }
    }
    return false;
}
void state1IntOrFloat(char ch, string line, int tracer, string &buffer, auto &fout)
{
    if (isInD(ch))
    {
        buffer.push_back(ch);
        state1IntOrFloat(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (isDelimiter(ch))
    {
        int posOfIden = INT_MAX;
        int integralBuffer = stoi(buffer);
        for (int i = 0; i < IntTable.size(); i++)
        {
            if (integralBuffer == IntTable[i].a)
            {
                posOfIden = i;
            }
        }
        if (posOfIden == INT_MAX)
        {
            IntTable.push_back({stoi(buffer)});
        }
        int pointer = (posOfIden == INT_MAX) ? int(IntTable.size()) - 1 : posOfIden;
        fout << 1 << " " << pointer << endl;
        state0(line[tracer - 1], line, tracer, buffer, fout);
    }
    else
    {
        cout << "error(tokenisation)" << endl;
        isError = true;
    }
}
void state0(char ch, string line, int tracer, string &buffer, auto &fout)
{
    buffer = "";
    if (tracer >= line.size())
    {
        return;
    }
    while (ch == ' ')
    {
        if (tracer >= line.size())
        {
            return;
        }
        ch = line[tracer];
        tracer++;
    }
    if (isInD(ch))
    {
        buffer.push_back(ch);
        state1IntOrFloat(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (ch == '*')
    {
        fout << 2 << " --"
             << endl;
        state0(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (ch == '!')
    {
        fout << 3 << " --"
             << endl;
        state0(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (ch == '(')
    {
        fout << 4 << " --"
             << endl;
        state0(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (ch == ')')
    {
        fout << 5 << " --"
             << endl;
        state0(line[tracer], line, tracer + 1, buffer, fout);
    }
    else if (ch == '$')
    {
        return;
    }
    else
    {
        cout << "error (tokenisation)" << endl;
        isError = true;
    }
}
void displayTables()
{
    cout << "integer Table :" << endl;
    for (int i = 0; i < IntTable.size(); i++)
    {
        cout << i << " " << IntTable[i].a << endl;
    }
    cout << endl;
}
void fillTable(vector<vector<char>> &table)
{
    table = {
        {'A', 'L', 'L', 'L', 'L', 'N'},
        {'G', 'N', 'G', 'G', 'N', 'G'},
        {'G', 'L', 'G', 'L', 'L', 'G'},
        {'G', 'N', 'G', 'G', 'N', 'G'},
        {'N', 'L', 'L', 'L', 'L', 'E'},
        {'G', 'N', 'G', 'G', 'N', 'G'}};
}
void fillProductions(map<vector<int>, int> &productions)
{
    productions[{1}] = 100;
    productions[{4, 100, 5}] = 100;
    productions[{100, 3}] = 100;
    productions[{100, 2, 100}] = 100;
}
bool parser(vector<pair<int, int>> inputStream, map<vector<int>, int> productions, vector<vector<char>> table, int &tracer, stack<uint32_t> &resStack)
{
    stack<int> s;
    s.push(0);
    int lastPushedToken = 0;
    while (tracer != inputStream.size())
    {
        int stackTop = s.top();
        if (table[lastPushedToken][inputStream[tracer].first] == 'L' || table[lastPushedToken][inputStream[tracer].first] == 'E')
        {
            s.push(inputStream[tracer].first);
            lastPushedToken = inputStream[tracer].first;
            tracer++;
        }
        else if (table[lastPushedToken][inputStream[tracer].first] == 'G')
        {
            int lastPoppedToken = -1;
            int topOfStackToken = lastPushedToken;
            vector<int> buffer;
            while (lastPoppedToken == -1 || table[topOfStackToken][lastPoppedToken] == 'G' || table[topOfStackToken][lastPoppedToken] == 'E')
            {
                while (s.top() >= 100)
                {
                    buffer.push_back(s.top());
                    s.pop();
                }
                lastPoppedToken = s.top();
                buffer.push_back(lastPoppedToken);
                s.pop();
                while (s.top() >= 100)
                {
                    buffer.push_back(s.top());
                    s.pop();
                }
                topOfStackToken = s.top();
            }
            reverse(buffer.begin(), buffer.end());
            if (productions.find(buffer) == productions.end())
            {
                return false;
            }
            vector<int> justInt = {1};
            vector<int> mult = {100, 2, 100};
            vector<int> facto = {100, 3};
            if (buffer == justInt)
            {
                int intTableIndex = inputStream[tracer - 1].second;
                resStack.push(IntTable[intTableIndex].a);
            }
            else if (buffer == mult)
            {
                uint32_t right = resStack.top();
                resStack.pop();
                uint32_t left = resStack.top();
                resStack.pop();
                resStack.push(multiply(left, right));
            }
            else if (buffer == facto)
            {
                uint32_t num = resStack.top();
                resStack.pop();
                resStack.push(factorial(num));
            }
            int toReplace = productions[buffer];
            lastPushedToken = topOfStackToken;
            s.push(toReplace);
        }
        else if (table[lastPushedToken][inputStream[tracer].first] == 'A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (s.empty())
        return true;
    return false;
}
int main()
{
    auto start = chrono::high_resolution_clock::now();
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("tokenOutput.txt");
    string buffer, line;
    vector<vector<char>> table;
    map<vector<int>, int> productions;
    stack<uint32_t> resStack;
    int tracer = 0;
    vector<pair<int, int>> inputStream;
    cout << "tokenisation  started" << endl;
    while (getline(fin, line))
    {
        line = trimLeadingWhitespaces(line) + "$";
        char ch = line[0];
        state0(ch, line, 1, buffer, fout);
    }
    fout.close();
    fin.close();
    cout << "tokenisation  completed" << endl;
    if (!isError)
        displayTables();
    fin.open("tokenOutput.txt");
    while (getline(fin, line))
    {
        if (line == "")
            continue;
        vector<string> splittedLine = splitString(line, ' ');
        int tokenType = stringToInt(splittedLine[0]);
        int ptr = stringToInt(splittedLine[1]);
        inputStream.push_back(make_pair(tokenType, ptr));
    }
    inputStream.push_back(make_pair(0, -1));
    fin.close();
    fillProductions(productions);
    fillTable(table);
    cout << "parsing and computing result.." << endl
         << endl;
    if (parser(inputStream, productions, table, tracer, resStack))
    {
        cout << "parsed successfully!\n";
        cout << "evaluated result of given expression: " << resStack.top() << endl
             << endl;
    }
    else
    {
        cout << "error parsing token number " << tracer;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "execution time: " << duration << " milliseconds" << endl;
    return 0;
}

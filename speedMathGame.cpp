#include <iostream> //
#include <windows.h> //
#include <conio.h> //
#include <cmath> //
#include <future> //
#include <atomic> //
#include <thread> //
#include <fstream> //

using namespace std;

// مقاسات الشاشات
// 46   110   156 width
// 30   40    44  hight

// دالة لإخفاء المؤشر
void hidecursor(bool visible)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// الدالة الأولى: الترحيبية: اسم اللعبة
void welcome()
{
    hidecursor(false); // اخفاء المؤشر
    cout << "Please enlarge The screen [F11 or Alt+Enter]\nThen Press Any Key";
    getch();
    system("cls"); // مسح الصفحة

    string a = "Speed Math Game.";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {69, 21});
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
        Sleep(150);
    }

    Sleep(2000);
    system("cls");
}

// الدالة الثانية: صفحة تسجيل الدخول
string login()
{
    string user, pass;
    bool incorrect;
    hidecursor(true); // اظهار المؤشر
    do
    {
        incorrect = false;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
        cout << "Speed Math Game";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 13});
        cout << "The Guest mode: Username = your name, Password = guest";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 16});
        cout << "Enter The Username: ";
        cin >> user;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 18});
        cout << "Enter The Password: ";
        cin >> pass;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 20});
        cout << "----------------------------------------";

        if (user == "salem" && pass == "melas")
        {
        }
        else if (user == "sloom" && pass == "1234")
        {
        }
        else if (user == "mounir" && pass == "1547")
        {
        }
        else if (user == "mohsen" && pass == "Password")
        {
        }
        else if (user == "moad" && pass == "7700")
        {
        }
        else if (user == "Abdullah" && pass == "3645")
        {
        }
        else if (user == "AbdulRahman" && pass == "1195")
        {
        }
        else if (pass == "guest")
        {
        }
        else
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 21});
            cout << "The Username or Password is Incorrect";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 22});
            cout << "Press Any Key to Try Again.";
            getch();
            incorrect = true;
            system("cls");
        }
    } while (incorrect);

    hidecursor(false); // اخفاء المؤشر
    system("cls"); // مسح الشاشة
    return user;
}

// الدالة الثالثة: الصفحة الرئيسية: خيارات start - about - exit
char home(string user, int score)
{
    char opt;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
    cout << "Speed Math Game";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 10});
    cout << "Welcome " << user;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {100, 10});
    cout << "Best score: " << score;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 15});
    cout << "1: Start Game";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 16});
    cout << "2: About Game";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 17});
    cout << "0: Exit";

    opt = getch();
    system("cls");
    return opt;
}

// صفحة قائمة انواع المسائل
char gameMode(int score)
{
    char opt;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
    cout << "Speed Math Game";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {100, 10});
    cout << "Best score: " << score;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 15});
    cout << "1: Plus";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 16});
    cout << "2: Minus";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 17});
    cout << "3: Multiply";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 18});
    cout << "4: Divide";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 19});
    cout << "5: Square";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 20});
    cout << "6: Back";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 21});
    cout << "0: Exit";

    opt = getch();
    system("cls");
    return opt;
}

// صفحة المعلومات عن اللعبة
void about()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
    cout << "Speed Math Game";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 10});
    cout << "Version 1.0";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 15});
    cout << "Maked By:";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 17});
    cout << "Mounir Al-Yazidi";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 18});
    cout << "Mohsen Al-Wahidi";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 19});
    cout << "Salem Al-Awlaki";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 20});
    cout << "Moad Al-Awlaki";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 21});
    cout << "Abdullah Al-Nasi";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 22});
    cout << "Abdul Rahman Al-Amuodi";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {50, 23});
    cout << "Salem Al-Zuhairi";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 30});
    cout << "Press Any Key to Back";
    getch();
    system("cls");
}

// دالة المؤقت 3 ثواني لإنتهاء وقت المسألة
bool timer()
{

    bool timeOut = false;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {37, 0});
    cout << "|";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {120, 0});
    cout << "|";

    for (int i = 1; i <= 82; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(short)(37 + i), 0});
        Sleep(36.5);
        cout << ":";
    }
    timeOut = true;
    return timeOut;
}

bool out; // متغير مساعد للدالة ReadCin لحفظ انتهاء الوقت ام لا

// دالة مساعدة للtimer لإدخال الإجابة اثناء عمل المؤقت
void ReadCin(atomic<bool> &run)
{
    while (run.load())
    {
        out = timer();
        run.store(false);
    }
}

// قراءة وكتابة الscore
int scoreAble(bool write, int score = 0)
{
    int s = 0;

    if (write)
    {
        ofstream writeInfo;
        writeInfo.open("score.txt");
        writeInfo << score;
        writeInfo.close();
    }
    else
    {
        ifstream readInfo;
        readInfo.open("score.txt");
        readInfo >> s;
        readInfo.close();
    }
    return s;
}

// الجسم الفعلي للعبة
void game(int mode, int bestScore)
{
    bool con;
    int score = 0;
    do
    {
        con = false;
        system("cls");

        double res, fres; // الخيارين
        srand(time(NULL));

        // انشاء رقمين عشوائيين
        int v1;
        int v2;

        // رقم الخيار الصحيح
        int solve = rand() % 2;

        if (mode == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            v1 = rand() % 50 + 1;
            v2 = rand() % 50 + 1;

            cout << v1 << " + " << v2;
            res = v1 + v2;
        }
        else if (mode == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            v1 = rand() % 50 + 1;
            v2 = rand() % 40 + 1;

            cout << v1 << " - " << v2;
            res = v1 - v2;
        }
        else if (mode == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            v1 = rand() % 12 + 1;
            v2 = rand() % 12 + 1;

            cout << v1 << " * " << v2;
            res = v1 * v2;
        }
        else if (mode == 4)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            v1 = rand() % 50 + 1;
            v2 = rand() % 12 + 1;

            cout << v1 << " / " << v2;
            res = v1 / v2;
        }
        else if (mode == 5)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            v1 = rand() % 10 + 1;
            v2 = rand() % 5 + 1;

            cout << v1 << " ^ " << v2;
            res = pow(v1, v2);
        }

        // ضبط الخيار الخاطئ
        int frange = rand() % 5 + 1; // نسبة الخطأ
        int signal = rand() % 2;     // سالب أو موجب
        if (signal == 1)
            frange *(-1);
        fres = res + frange; // الناتج الخاطئ النهائي

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
        cout << "Speed Math Game";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {100, 10});
        cout << "Best Score: " << bestScore;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 10});
        cout << "Score: " << score;

        if (solve == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 21});
            cout << "( A )";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {41, 23});
            cout << res;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {105, 21});
            cout << "( B )";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {106, 23});
            cout << fres;
        }
        else
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 21});
            cout << "( A )";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {41, 23});
            cout << fres;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {105, 21});
            cout << "( B )";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {106, 23});
            cout << res;
        }

        atomic<bool> run(true);
        thread cinThread(ReadCin, ref(run));

        char value;
        out = false;
        bool end;
        while (run.load())
        {
            value = getch();
            value = toupper(value);
            if (value == 'A' || value == 'B' || out)
                break;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {1, 2});
        end = out;
        run.store(false);
        cinThread.join();

        if (((solve == 0 && value == 'A') || (solve == 1 && value == 'B')) && !end)
        {
            con = true;
            score++;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {67, 35});
            cout << "The answer is correct";
            Sleep(1000);
            system("cls");
        }
        else
        {
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {70, 5});
            cout << "Speed Math Game";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {100, 10});
            cout << "Best Score: " << bestScore;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {40, 10});
            cout << "Score: " << score;

            if (score > bestScore)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {65, 30});
                cout << "Excellent New Best Score :)";

                scoreAble(true, score);
                bestScore = score;
            }

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {75, 15});
            end == false ? cout << "Game Over" : cout << "Time Out";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {59, 20});
            cout << "1: Again          2: Back          0: Exit";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {68, 35});
            if (!end)
                cout << "The answer is incorrect";

            bool chooseAgain;
            do
            {
                chooseAgain = false;
                char choose = getch();

                if (choose == '1')
                {
                    score = 0;
                    con = true;
                }
                else if (choose == '2')
                {
                    system("cls");
                    break;
                }
                else if (choose == '0')
                {
                    exit(0);
                }
                else
                {
                    cout << "\r";
                    chooseAgain = true;
                }

            } while (chooseAgain);
        }

    } while (con);
}

// الدالة الرئيسية
int main()
{
    welcome();
    string user = login(); // user هو القيمة الراجعة من login

    while (true)
    {
        ifstream readInfo;
        readInfo.open("score.txt");

        if (!readInfo.is_open())
        {
            scoreAble(true);
        }

        int s;
        readInfo >> s;

        char page = home(user, s);

        char mode;
        if (page == '1')
        {
            mode = gameMode(s);

            if (mode == '1')
            {
                game(1, s);
            }
            if (mode == '2')
            {
                game(2, s);
            }
            if (mode == '3')
            {
                game(3, s);
            }
            if (mode == '4')
            {
                game(4, s);
            }
            if (mode == '5')
            {
                game(5, s);
            }
            if (mode == '6')
            {
                break;
            }
            if (mode == '0')
            {
                exit(0);
            }
        }
        else if (page == '2')
        {
            about();
        }
        else if (page == '0')
        {
            exit(0);
        }
    }
}
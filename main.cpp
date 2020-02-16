#include "JSON.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

/*----------------------------Containers----------------------------*/
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <unordered_map>
/*----------------------------Containers----------------------------*/

using namespace std;

struct TestArrObj
{
    string str;

    void Serialize(CJSON &json) const 
    {
        json.AddPair("str", str);
    }

    void Deserialize(CJSON &json) 
    {
        str = json.GetValue<string>("str");
    }

    void SetVal()
    {
        str = "Hello World!";
    }
};


class PrimitiveTestClass
{
    public:
        PrimitiveTestClass() 
        {
            pc = nullptr;
            puc = nullptr;
            ps = nullptr;
            pus = nullptr;
            pi = nullptr;
            pui = nullptr;
            pl = nullptr;
            pul = nullptr;
            pll = nullptr;
            pull = nullptr;
            pf = nullptr;
            pd = nullptr;
            pld = nullptr;
            pto = nullptr;
            str = nullptr;
        }

        void Serialize(CJSON &json) const 
        {
            json.AddPair("c", c);
            json.AddPair("uc", uc);
            json.AddPair("s", s);
            json.AddPair("us", us);
            json.AddPair("i", i);
            json.AddPair("ui", ui);
            json.AddPair("l", l);
            json.AddPair("ul", ul);
            json.AddPair("ll", ll);
            json.AddPair("ull", ull);
            json.AddPair("f", f);
            json.AddPair("d", d);
            json.AddPair("ld", ld);

            json.AddPair("str", str);

            json.AddPair("pc", pc, SIZE);
            json.AddPair("puc", puc, SIZE);
            json.AddPair("ps", ps, SIZE);
            json.AddPair("pus", pus, SIZE);
            json.AddPair("pi", pi, SIZE);
            json.AddPair("pui", pui, SIZE);
            json.AddPair("pl", pl, SIZE);
            json.AddPair("pul", pul, SIZE);
            json.AddPair("pll", pll, SIZE);
            json.AddPair("pull", pull, SIZE);
            json.AddPair("pf", pf, SIZE);
            json.AddPair("pd", pd, SIZE);
            json.AddPair("pld", pld, SIZE);

            json.AddPair("pto", pto, SIZE);
            json.AddPair("spi", spi, SIZE);
            json.AddPair("spto", spto, SIZE);
        }

        void Deserialize(CJSON &json)
        {
            c = json.GetValue<char>("c");
            uc = json.GetValue<unsigned char>("uc");
            s = json.GetValue<short>("s");
            us = json.GetValue<unsigned short>("us");
            i = json.GetValue<int>("i");
            ui = json.GetValue<unsigned int>("ui");
            l = json.GetValue<long>("l");
            ul = json.GetValue<unsigned long>("ul");
            ll = json.GetValue<long long>("ll");
            ull = json.GetValue<unsigned long long>("ull");
            f = json.GetValue<float>("f");
            d = json.GetValue<double>("d");
            ld = json.GetValue<long double>("ld");

            str = json.GetValue<char*>("str");

            size_t tmp;

            pc = json.GetValue<char*>("pc", tmp);
            puc = json.GetValue<unsigned char*>("puc", tmp);
            ps = json.GetValue<short*>("ps", tmp);
            pus = json.GetValue<unsigned short*>("pus", tmp);
            pi = json.GetValue<int*>("pi", tmp);
            pui = json.GetValue<unsigned int*>("pui", tmp);
            pl = json.GetValue<long*>("pl", tmp);
            pul = json.GetValue<unsigned long*>("pul", tmp);
            pll = json.GetValue<long long*>("pll", tmp);
            pull = json.GetValue<unsigned long long*>("pull", tmp);
            pf = json.GetValue<float*>("pf", tmp);
            pd = json.GetValue<double*>("pd", tmp);
            pld = json.GetValue<long double*>("pld", tmp);

            pto = json.GetValue<TestArrObj*>("pto", tmp);
            spi = json.GetValue<shared_ptr<int>>("spi", tmp);
            spto = json.GetValue<shared_ptr<TestArrObj>>("spto", tmp);
        } 

        void Print()
        {
            cout << "c: " << (int)c << endl; 
            cout << "uc: " << (int)uc << endl; 
            cout << "s: " << s << endl;
            cout << "us: " << us << endl; 
            cout << "i: " << i << endl; 
            cout << "ui: " << ui << endl; 
            cout << "l: " << l << endl; 
            cout << "ul: " << ul << endl; 
            cout << "ll: " << ll << endl; 
            cout << "ull: " << ull << endl; 
            cout << "f: " << f << endl; 
            cout << "d: " << d << endl; 
            cout << "ld: " << ld << endl; 

            cout << "str: " << str << endl;

            cout << "pc: ";
            PrintArr(pc);
            cout << "puc: ";
            PrintArr(puc);
            cout << "ps: ";
            PrintArr(ps);
            cout << "pus: ";
            PrintArr(pus);
            cout << "pi: ";
            PrintArr(pi);
            cout << "pui: ";
            PrintArr(pui);
            cout << "pl: ";
            PrintArr(pl);
            cout << "pul: ";
            PrintArr(pul);
            cout << "pll: ";
            PrintArr(pll);
            cout << "pull: ";
            PrintArr(pull);
            cout << "pf: ";
            PrintArr(pf);
            cout << "pd: ";
            PrintArr(pd);
            cout << "pld: ";
            PrintArr(pld);

            cout << "pto: ";
            for (size_t i = 0; i < SIZE; i++)
            {
                cout << pto[i].str << ", ";
            }
            
            cout << endl;

            cout << "spi: ";
            for (size_t i = 0; i < SIZE; i++)
            {
                cout << (&*spi)[i] << ", ";
            }
            
            cout << endl;

            cout << "spto: ";
            for (size_t i = 0; i < SIZE; i++)
            {
                cout << (&*spto)[i].str << ", ";
            }
            
            cout << endl;
        }

        template<class T>
        void PrintArr(T arr)
        {
            for (size_t i = 0; i < SIZE; i++)
            {
                cout << arr[i] << ", ";
            }
            
            cout << endl;
        }

        void AddValues()
        {
            c = 0xFF;
            uc = 0xFF;
            s = 0xFFFF;
            us = 0xFFFF;
            i = 0xFFFFF;
            ui = 0xFFFFF;
            l = 0xFFFFF;
            ul = 0xFFFFF;
            ll = 0xFFFFF;
            ull = 0xFFFFF;
            f = 1.342323;
            d = 432.324324324;
            ld = 423432.3465435435;

            str = new char[strlen("Hello World!") + 1];
            strcpy(str, "Hello World!");
            str[strlen("Hello World!")] = '\0';

            pc = FillValues<char *>();
            puc = FillValues<unsigned char *>();
            ps = FillValues<short *>();
            pus = FillValues<unsigned short *>();
            pi = FillValues<int *>();
            pui = FillValues<unsigned int *>();
            pl = FillValues<long *>();
            pul = FillValues<unsigned long *>();
            pll = FillValues<long long *>();
            pull = FillValues<unsigned long long *>();
            pf = FillValues<float *>();
            pd = FillValues<double *>();
            pld = FillValues<long double *>();

            pto = new TestArrObj[SIZE];
            for (size_t i = 0; i < SIZE; i++)
            {
                pto[i].SetVal();
            }
            
            spi = shared_ptr<int>(new int[SIZE]);
            for (size_t i = 0; i < SIZE; i++)
            {
                (&*spi)[i] = 10;
            }

            spto = shared_ptr<TestArrObj>(new TestArrObj[SIZE], default_delete<TestArrObj[]>());
            for (size_t i = 0; i < SIZE; i++)
            {
                (&*spto)[i].SetVal();
            }   
        }

        PrimitiveTestClass &operator=(const PrimitiveTestClass &other)
        {
            c = other.c;
            uc = other.uc;
            s = other.s;
            us = other.us;
            i = other.i;
            ui = other.ui;
            l = other.l;
            ul = other.ul;
            ll = other.ll;
            ull = other.ull;
            f = other.f;
            d = other.d;
            ld = other.ld;

            str = new char[strlen("Hello World!") + 1];
            memcpy(str, other.str, strlen("Hello World!") + 1);

            pc = new char[SIZE];
            memcpy(pc, other.pc, SIZE);
            puc = new unsigned char[SIZE];
            memcpy(puc, other.puc, SIZE);
            ps = new short[SIZE];
            memcpy(ps, other.ps, SIZE * sizeof(short));
            pus = new unsigned short[SIZE];
            memcpy(pus, other.pus, SIZE * sizeof(unsigned short));
            pi = new int[SIZE];
            memcpy(pi, other.pi, SIZE * sizeof(int));
            pui = new unsigned int[SIZE];
            memcpy(pui, other.pui, SIZE * sizeof(unsigned int));
            pl = new long[SIZE];
            memcpy(pl, other.pl, SIZE * sizeof(long));
            pul = new unsigned long[SIZE];
            memcpy(pul, other.pul, SIZE * sizeof(unsigned long));
            pll = new long long[SIZE];
            memcpy(pll, other.pll, SIZE * sizeof(long long));
            pull = new unsigned long long[SIZE];
            memcpy(pull, other.pull, SIZE * sizeof(unsigned long long));
            pf = new float[SIZE];
            memcpy(pf, other.pf, SIZE * sizeof(float));
            pd = new double[SIZE];
            memcpy(pd, other.pd, SIZE * sizeof(double));
            pld = new long double[SIZE];
            memcpy(pld, other.pld, SIZE * sizeof(long double));

            pto = new TestArrObj[SIZE];
            for (size_t i = 0; i < SIZE; i++)
            {
                pto[i] = other.pto[i];
            }

            spi = other.spi;
            spto = other.spto;
        }

        ~PrimitiveTestClass()
        {
            delete[] str;

            delete[] pc;
            delete[] puc;
            delete[] ps;
            delete[] pus;
            delete[] pi;
            delete[] pui;
            delete[] pl;
            delete[] pul;
            delete[] pll;
            delete[] pull;
            delete[] pf;
            delete[] pld;
            delete[] pd;
            delete[] pto;
        }

    private:
        const int SIZE = 10;

        template<class T>
        T FillValues()
        {
            T ret = new typename std::remove_pointer<T>::type[SIZE];
            for (size_t i = 0; i < SIZE; i++)
            {
                ret[i] = 0xFF;
            }
            
            return ret;
        }

        char c;
        unsigned char uc;
        short s;
        unsigned short us;
        int i;
        unsigned int ui;
        long l;
        unsigned long ul;
        long long ll;
        unsigned long long ull;
        float f;
        double d;
        long double ld;

        char *str;

        char *pc;
        unsigned char *puc;
        short *ps;
        unsigned short *pus;
        int *pi;
        unsigned int *pui;
        long *pl;
        unsigned long *pul;
        long long *pll;
        unsigned long long *pull;
        float *pf;
        double *pd;
        long double *pld;
        TestArrObj *pto;

        shared_ptr<int> spi;
        shared_ptr<TestArrObj> spto;
};

class BaseFSNode
{
    public:
        void Serialize(CJSON &json) const
        {
            json.AddPair("name", m_Name);
            json.AddPair("path", m_Path);
        }

        void Deserialize(CJSON &json)
        {
            m_Name = json.GetValue<string>("name");
            m_Path = json.GetValue<string>("path");
        }

        void Print()
        {
            cout << "Name: " << m_Name << endl;
            cout << "Path: " << m_Path << endl;
        }

    protected:
        string m_Name;
        string m_Path;
};

class File : public BaseFSNode
{
    public:
        File() {}
        File(string Name, string Path, size_t Size) 
        {
            m_Name = Name;
            m_Path = Path;
            m_Size = Size;
        }

        void Serialize(CJSON &json) const
        {
            BaseFSNode::Serialize(json);
            json.AddPair("size", m_Size);
        }

        void Deserialize(CJSON &json)
        {
            BaseFSNode::Deserialize(json);
            m_Size = json.GetValue<size_t>("size");
        }

        void Print()
        {
            BaseFSNode::Print();
            cout << "Size: " << m_Size << endl;
        }

    private:
        size_t m_Size;
};

class Folder : public BaseFSNode
{
    public:
        Folder() {}
        Folder(string Name, string Path)
        {
            m_Name = Name;
            m_Path = Path;
        }

        void Serialize(CJSON &json) const
        {
            BaseFSNode::Serialize(json);
            json.AddPair("files", m_Files);
        }

        void Deserialize(CJSON &json)
        {
            BaseFSNode::Deserialize(json);
            m_Files = json.GetValue<vector<shared_ptr<File>>>("files");
        }

        void Print()
        {
            BaseFSNode::Print();
            for(auto &&e : m_Files)
            {
                e->Print();
            }
        }

        void AddFile(File *file)
        {
            m_Files.push_back(shared_ptr<File>(file));
        }

    private:
        vector<shared_ptr<File>> m_Files;
};

/*-------------------Serialize-------------------*/
void SerializeContainers(CJSON &json)
{
    cout << "-------------------Serialize-------------------\n" << endl;

    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "std::array: " << json.Serialize(arr) << endl;

    deque<string> dequeue;
    dequeue.push_back("Test");
    dequeue.push_back("Hallo");
    dequeue.push_back("Welt");
    dequeue.push_back("List");
    cout << "std::deque: " << json.Serialize(dequeue) << endl;

    forward_list<int> flist;
    flist.push_front(5);
    flist.push_front(3);
    flist.push_front(2);
    flist.push_front(7);

    map<string, int> jobj;
    jobj["Num1"] = 5;
    jobj["Num5"] = 6;
    jobj["Num4"] = 8;
    jobj["Num2"] = 9;
    cout << "std::map: " << json.Serialize(jobj) << endl;

    multimap<string, int> mmap;
    mmap.insert(pair<string, int>("Test", 1));
    mmap.insert(pair<string, int>("Test", 2));
    mmap.insert(pair<string, int>("Test", 3));
    mmap.insert(pair<string, int>("Test1", 4));
    mmap.insert(pair<string, int>("Test2", 1));
    mmap.insert(pair<string, int>("Test1", 5));
    cout << "std::multimap: " << json.Serialize(mmap) << endl;

    unordered_map<string, int> umap;
    umap["Test"] = 5;
    umap["Test2"] = 2;
    umap["Test4"] = 4;
    cout << "std::unordered_map: " << json.Serialize(umap) << endl;

    unordered_multimap<string, int> ummap;
    ummap.insert(pair<string, int>("Test", 1));
    ummap.insert(pair<string, int>("Test", 2));
    ummap.insert(pair<string, int>("Test", 3));
    ummap.insert(pair<string, int>("Test1", 4));
    ummap.insert(pair<string, int>("Test2", 1));
    ummap.insert(pair<string, int>("Test1", 5));
    cout << "std::unordered_multimap: " << json.Serialize(ummap) << endl;

    vector<int> ivec;
    ivec.push_back(3);
    ivec.push_back(35);
    cout << "std::vector: " << json.Serialize(ivec) << endl;
}

void SerializePrimitives(CJSON &json)
{
    PrimitiveTestClass ptc;
    ptc.AddValues();

    cout << "PrimitiveTestClass: " << json.Serialize(ptc) << endl;
}

void SerializeObject(CJSON &json)
{
    Folder dir("Test", "/home/test");
    dir.AddFile(new File("Test.png", "/home/test/Test", 2048));
    dir.AddFile(new File("Test.txt", "/home/test/Test", 512));
    dir.AddFile(new File("Test.mp3", "/home/test/Test", 10000000));

    cout << "Folder: " << json.Serialize(dir) << endl;
}
/*-------------------Serialize-------------------*/

template<class T>
void Print(T &d)
{
    for(auto &&e : d)
    {
        cout << e << ",";
    }

    cout << endl;
}

template<class T>
void PrintMap(T &d)
{
    for(auto &&e : d)
    {
        cout << e.first << " " << e.second << ",";
    }

    cout << endl;
}

/*-------------------Deserialize-------------------*/
void DeserializeContainers(CJSON &json)
{
    cout << "\n-------------------Deserialize-------------------\n" << endl;

    deque<string> dequeue = json.Deserialize<deque<string>>("[\"Test\",\"Hallo\",\"Welt\",\"List\"]");
    cout << "std::deque: ";
    Print(dequeue);

    forward_list<int> flist = json.Deserialize<forward_list<int>>("[7,2,3,5]");
    cout << "std::forward_list: ";
    Print(flist);

    list<string> list = json.Deserialize<std::list<string>>("[\"5\",\"Welt\",\"Test212312\",\"Serial\"]");
    cout << "std::list: ";
    Print(list);

    map<string, int> jobj = json.Deserialize<map<string, int>>("{\"Num1\":5,\"Num2\":9,\"Num4\":8,\"Num5\":6}");
    cout << "std::map: ";
    PrintMap(jobj);

    multimap<string, int> mmap = json.Deserialize<multimap<string, int>>("{\"Test\":[1,2,3],\"Test1\":[4,5],\"Test2\":[1]}");
    cout << "std::multimap: ";
    PrintMap(mmap);

    unordered_map<string, int> umap = json.Deserialize<unordered_map<string, int>>("{\"Test4\":4,\"Test\":5,\"Test2\":2}");
    cout << "std::unordered_map: ";
    PrintMap(umap);

    unordered_multimap<string, int> ummap = json.Deserialize<unordered_multimap<string, int>>("{\"Test\":[1,2,3],\"Test1\":[4,5],\"Test2\":[1]}");
    cout << "std::unordered_multimap: ";
    PrintMap(ummap);

    vector<int> ivec = json.Deserialize<vector<int>>("[3,35]");
    cout << "std::vector: ";
    Print(ivec);
}

void DeserializePrimitives(CJSON &json)
{
    PrimitiveTestClass ptc;
    ptc = json.Deserialize<PrimitiveTestClass>("{\"c\":-1,\"d\":432.324324,\"f\":1.342323,\"i\":1048575,\"l\":1048575,\"ld\":423432.346544,\"ll\":1048575,\"pc\":[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],\"pd\":[255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000],\"pf\":[255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000],\"pi\":[255,255,255,255,255,255,255,255,255,255],\"pl\":[255,255,255,255,255,255,255,255,255,255],\"pld\":[255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000,255.000000],\"pll\":[255,255,255,255,255,255,255,255,255,255],\"ps\":[255,255,255,255,255,255,255,255,255,255],\"pto\":[{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"}],\"puc\":[255,255,255,255,255,255,255,255,255,255],\"pui\":[255,255,255,255,255,255,255,255,255,255],\"pul\":[255,255,255,255,255,255,255,255,255,255],\"pull\":[255,255,255,255,255,255,255,255,255,255],\"pus\":[255,255,255,255,255,255,255,255,255,255],\"s\":-1,\"str\":\"Hello World!\",\"uc\":255,\"ui\":1048575,\"ul\":1048575,\"ull\":1048575,\"us\":65535, \"spi\":[10,10,10,10,10,10,10,10,10,10], \"spto\":[{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"},{\"str\":\"Hello World!\"}]}");
    cout << "PrimitiveTestClass: " << endl;
    ptc.Print();
}

void DeserializeObject(CJSON &json)
{
    Folder dir = json.Deserialize<Folder>("{\"files\":[{\"name\":\"Test.png\",\"path\":\"\\/home\\/test\\/Test\",\"size\":2048},{\"name\":\"Test.txt\",\"path\":\"\\/home\\/test\\/Test\",\"size\":512},{\"name\":\"Test.mp3\",\"path\":\"\\/home\\/test\\/Test\",\"size\":10000000}],\"name\":\"Test\",\"path\":\"\\/home\\/test\"}");
    dir.Print();
}
/*-------------------Deserialize-------------------*/

/*-------------------Error cases-------------------*/
string GetEnumName(JSONErrorType err)
{
    switch (err)
    {
        case JSONErrorType::NAME_ALREADY_EXITS: return "NAME_ALREADY_EXITS";
        case JSONErrorType::NAME_NOT_FOUND: return "NAME_NOT_FOUND";
        case JSONErrorType::INVALID_JSON_OBJECT: return "INVALID_JSON_OBJECT";
        case JSONErrorType::INVALID_ARRAY: return "INVALID_ARRAY";
        case JSONErrorType::INVALID_TYPE: return "INVALID_TYPE";
        case JSONErrorType::INVALID_CAST: return "INVALID_CAST";
        case JSONErrorType::EXPECTED_BOOL: return "EXPECTED_BOOL";
        case JSONErrorType::EXPECTED_NULL: return "EXPECTED_NULL";
        case JSONErrorType::EXPECTED_NUM: return "EXPECTED_NUM";
        case JSONErrorType::WRONG_PLACED_SEPERATOR: return "WRONG_PLACED_SEPERATOR";
        case JSONErrorType::MISSING_KEY: return "MISSING_KEY";
        case JSONErrorType::MISSING_VALUE: return "MISSING_VALUE";
        case JSONErrorType::MISSING_SEPERATOR: return "MISSING_SEPERATOR";
    }
}

void ExpectedError(string TestCase, JSONErrorType Raised, JSONErrorType Expected)
{
    if(Raised == Expected)
        cout << "Case: " << TestCase << ": The raised exception is equal the expected one! ENUM: " << GetEnumName(Raised) << endl;
    else
        cout << "Case: " << TestCase << ": Raised: " << GetEnumName(Raised) << " != Expected: " << GetEnumName(Expected) << endl;
}

void DeserializeMalformedJSON(CJSON &json)
{
    //Key doesn't begin with '"'.
    ifstream in("json/missingquotes.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingquotes", e.GetErrType(), JSONErrorType::MISSING_KEY);
        }
        
        in.close();
    }

    //Key doesn't end with '"'.
    in.open("json/missingquotes2.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingquotes2", e.GetErrType(), JSONErrorType::MISSING_SEPERATOR);
        }
        
        in.close();
    }

    //Missing '{' at begin.
    in.open("json/objectbeginmissing.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("objectbeginmissing", e.GetErrType(), JSONErrorType::INVALID_JSON_OBJECT);
        }
        
        in.close();
    }

    //Missing '}' at end.
    in.open("json/objectendmissing.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("objectendmissing", e.GetErrType(), JSONErrorType::INVALID_JSON_OBJECT);
        }
        
        in.close();
    }

    //Missing '[' at array begin.
    in.open("json/missingbracketarray.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingbracketarray", e.GetErrType(), JSONErrorType::MISSING_KEY);
        }
        
        in.close();
    }

    //Missing ']' at array end.
    in.open("json/missingbracketarray2.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingbracketarray2", e.GetErrType(), JSONErrorType::INVALID_JSON_OBJECT);
        }
        
        in.close();
    }

    //Invalid types
    in.open("json/wrongtypes.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("wrongtypes", e.GetErrType(), JSONErrorType::INVALID_CAST);
        }
        
        in.close();
    }

    //Missing comma
    in.open("json/missingcomma.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingcomma", e.GetErrType(), JSONErrorType::MISSING_SEPERATOR);
        }
        
        in.close();
    }

    //Missing colon
    in.open("json/missingcolon.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingcolon", e.GetErrType(), JSONErrorType::MISSING_SEPERATOR);
        }
        
        in.close();
    }

    //Missing comma in array
    in.open("json/missingcomma2.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("missingcomma2", e.GetErrType(), JSONErrorType::MISSING_SEPERATOR);
        }
        
        in.close();
    }

    //Missing '}' at object in array
    in.open("json/objectinarray.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("objectinarray", e.GetErrType(), JSONErrorType::MISSING_KEY);
        }
        
        in.close();
    }

    //Missing '{' at object in array
    in.open("json/objectinarray2.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("objectinarray2", e.GetErrType(), JSONErrorType::INVALID_CAST);
        }
        
        in.close();
    }

    //Wrong placed comma.
    in.open("json/wrongplacedcomma.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("wrongplacedcomma", e.GetErrType(), JSONErrorType::WRONG_PLACED_SEPERATOR);
        }
        
        in.close();
    }

    //Invalid cast
    in.open("json/invalidcast.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("invalidcast", e.GetErrType(), JSONErrorType::INVALID_CAST);
        }
        
        in.close();
    }

    //nullptr
    in.open("json/nullptr.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("nullptr", e.GetErrType(), JSONErrorType::INVALID_CAST);
        }
        
        in.close();
    }

    //nullptr key
    in.open("json/nullptrkey.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("nullptrkey", e.GetErrType(), JSONErrorType::MISSING_KEY);
        }
        
        in.close();
    }

    //nullptr value
    in.open("json/nullptrvalue.json", ios::in);
    if(in.is_open())
    {
        stringstream ss;

        ss << in.rdbuf();

        try
        {
            Folder dir = json.Deserialize<Folder>(ss.str());
        }
        catch(const CJSONException& e)
        {
            ExpectedError("nullptrvalue", e.GetErrType(), JSONErrorType::INVALID_CAST);
        }
        
        in.close();
    }
}
/*-------------------Error cases-------------------*/

int main(int argc, char const *argv[])
{
    CJSON json;

    SerializeContainers(json);
    DeserializeContainers(json);
    SerializePrimitives(json);
    DeserializePrimitives(json);
    SerializeObject(json);
    DeserializeObject(json);

    DeserializeMalformedJSON(json);

    return 0;
}


# CJSON

## Overview

Object orientated JSON serializer and deserializer. You can easily serialize and deserialize your objects, arrays, pointers, smart pointers and STL containers to and from JSON. All primitive, array and STL container types, except sets are supported. To use this library your compiler need to support at least C++11.

## How to use the library?

You need to add the JSON.hpp to your include paths.

### Example of how to use this library.

```C++
#include <iostream>
#include <JSON.hpp>

using namespace std;

class MyClass
{
    public:
        MyClass() {}    //<-- Default constructor is necessary for deserialization.

        void Serialize(CJSON &json) const
        {
            json.AddPair("name", m_Name);
        }

        void Deserialize(CJSON &json)
        {
            m_Name = json.GetValue<string>("name");
        }

        void SetName(string Name)
        {
            m_Name = Name;
        }

        string GetName()
        {
            return m_Name;
        }

    private:
        string m_Name;
};

int main()
{
    MyClass my1;
    my1.SetName("Peter");

    CJSON json;
    cout << json.Serialize(my1) << endl;
    // Expected output '{"name":"Peter"}'

    MyClass my2 = json.Deserialize<MyClass>("{\"name\":\"Peter\"}");
    cout << my2.GetName() << endl;
    // Expected output 'Peter'

    return 0;
}
```

For more example you can inspect the main.cpp file, which contains many testing cases.

## How to build the example project?

First you need cmake from https://cmake.org/.
After you have installed cmake you need to create a build directory inside this directory.
Open a terminal and navigate to the build directory, alternative you can use the cmake-gui, but I will describe the terminal version. Since cmake supports many build system I used in this example `ninja`, but you can use whatever you want.

```bash
cmake .. -G "Ninja"
ninja -j4
```

Now you can execute the compiled project.

## License

This library is under the [MIT License](LICENSE)

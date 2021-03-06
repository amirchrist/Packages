/* SYNTAX TEST "c++.sublime-syntax" */
#ifndef IGUARD_
 /* <- keyword.control.import */
#define IGUARD_
 /* <- keyword.control.import.define */
struct foo* alloc_foo();
/* <- storage.type */
       /* <- entity.name.type */
            /* <- entity.name.function */
#endif
 /* <- keyword.control.import */


/////////////////////////////////////////////
// Strings
/////////////////////////////////////////////

char str1[] = "abc";
/*            ^ punctuation.definition.string.begin */
/*             ^ string.quoted.double */
/*                ^ punctuation.definition.string.end */

char str2[] = u8"abc";
/*            ^ storage.type.string */
/*              ^ punctuation.definition.string.begin */
/*               ^ string.quoted.double */

char16_t str3[] = u"abc";
/*                ^ storage.type.string */
/*                 ^ punctuation.definition.string.begin */
/*                  ^ string.quoted.double */

char32_t str4[] = U"abc";
/*                ^ storage.type.string */
/*                 ^ punctuation.definition.string.begin */
/*                  ^ string.quoted.double */

wchar_t str5[] = L"abc";
/*               ^ storage.type.string */
/*                ^ punctuation.definition.string.begin */
/*                 ^ string.quoted.double */

char str6[] = "\"|\n|\r|\0|\x41";
/*             ^ constant.character.escape */
/*                ^ constant.character.escape */
/*                   ^ constant.character.escape */
/*                      ^ constant.character.escape */
/*                         ^ constant.character.escape */

char rawStr1[] = R"("This is a raw string")";
/*               ^ storage.type.string */
/*                ^ punctuation.definition.string.begin */
/*                  ^ string.quoted.double */
/*                                        ^ punctuation.definition.string.end */

char rawStr2[] = R"A*!34( )" )A*!34";
/*               ^ storage.type.string */
/*                ^ punctuation.definition.string.begin */
/*                      ^ punctuation.definition.string.begin */
/*                        ^ string.quoted.double */
/*                           ^ punctuation.definition.string.end */
/*                                 ^ punctuation.definition.string.end */


/////////////////////////////////////////////
// Storage Types
/////////////////////////////////////////////

void* ptr;
/* <- storage.type */

bool b;
/* <- storage.type */

char ch;
/* <- storage.type */

char16_t ch16;
/* <- storage.type */

char32_t ch32;
/* <- storage.type */

wchar_t wch;
/* <- storage.type */

unsigned int ui;
/* <- storage.type */
/*       ^ storage.type */

signed long l;
/* <- storage.type */
/*     ^ storage.type */

short s;
/* <- storage.type */

auto a = 2;
/* <- storage.type */

decltype(s) dt;
/* <- storage.type */

float f;
/* <- storage.type */

double d;
/* <- storage.type */


/////////////////////////////////////////////
// Storage Modifiers
/////////////////////////////////////////////

alignas(16) char array[256];
/* <- storage.modifier */

const int XYZ = 2;
/* <- storage.modifier */

constexpr int ABC = 3 + 5;
/* <- storage.modifier */

thread_local int x;
/* <- storage.modifier */


/////////////////////////////////////////////
// Control Keywords
/////////////////////////////////////////////

static_assert(x >= 0);
/* <- keyword.control */

noexcept(f());
/* <- keyword.control */

if (x < 5)
/* <- keyword.control */
{}
else
/* <- keyword.control */
{}

switch (x)
/* <- keyword.control */
{
case 1:
/* <- keyword.control */
    break;
    /* <- keyword.control */
default:
/* <- keyword.control */
    break;
    /* <- keyword.control */
}

do
/* <- keyword.control */
{
    if (y == 3)
        continue;
        /* <- keyword.control */
} while (y < x);
/*^ keyword.control */

goto label;
/* <- keyword.control */

try
/* <- keyword.control */
{
    throw std::string("xyz");
    /* <- keyword.control */
}
catch (...)
/* <- keyword.control */
{
}

int* ptr = new int(2);
/*         ^ keyword.control */

delete ptr;
/* <- keyword.control */

return 123;
/* <- keyword.control */


/////////////////////////////////////////////
// Operator Keywords
/////////////////////////////////////////////

int x = alignof(char);
/*      ^ keyword.operator */

int x = sizeof(char);
/*      ^ keyword.operator */


/////////////////////////////////////////////
// Cast Keywords
/////////////////////////////////////////////

const_cast<int>(2.0);
/* <- keyword.operator.cast */

dynamic_cast<int>(2.0);
/* <- keyword.operator.cast */

reinterpret_cast<int>(2.0);
/* <- keyword.operator.cast */

static_cast<int>(2.0);
/* <- keyword.operator.cast */


/////////////////////////////////////////////
// Language Constants
/////////////////////////////////////////////

bool t = true;
/*       ^ constant.language */

bool f = false;
/*       ^ constant.language */

int* p = nullptr;
/*       ^ constant.language */

char ch[] = __func__;
/*          ^ constant.language */


/////////////////////////////////////////////
// Support Constants
/////////////////////////////////////////////

std::cout << __FILE__ << '\n';
/*           ^ support.constant */

std::cout << __FUNCTION__ << '\n';
/*           ^ support.constant */

std::cout << __LINE__ << '\n';
/*           ^ support.constant */


/////////////////////////////////////////////
// Numeric Constants
/////////////////////////////////////////////

int dec = 1234567890;
/*        ^ constant.numeric */

int oct = 01234567;
/*        ^ constant.numeric */

int hex = 0x1234567890ABCDEF;
/*        ^ constant.numeric */

float fixed = 123.456;
/*            ^ constant.numeric */

float sci1 = 1.23e10;
/*           ^ constant.numeric */

float sci2 = 14.23e+14;
/*           ^ constant.numeric */

float sci3 = 18e-12;
/*           ^ constant.numeric */


/////////////////////////////////////////////
// Functions
/////////////////////////////////////////////

// function prototype
void abcdWXYZ1234();
/*   ^ entity.name.function */

// function definition
void abcdWXYZ1234()
/*   ^ entity.name.function */
{
}


/////////////////////////////////////////////
// Classes
/////////////////////////////////////////////

class BaseClass // comment
/* <- storage.type */
/*    ^ entity.name.type */
/*              ^ comment.line */
{
public:
/* <- storage.modifier */
protected:
/* <- storage.modifier */
private:
/* <- storage.modifier */

    static int x;
    /* <- storage.modifier */

    virtual void doSomething() const = 0;
    /* <- storage.modifier */
    /*                         ^ storage.modifier */
};

class DerivedClass : public BaseClass
{
    virtual void doSomething() const override final;
    /*                         ^ storage.modifier */
    /*                               ^ storage.modifier */
    /*                                        ^ storage.modifier */
};

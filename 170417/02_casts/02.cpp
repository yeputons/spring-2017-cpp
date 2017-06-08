reinterpret_cast означает "запиши кусок памяти, как поток байт".
Вы должны гарантировать, что там нет проблем с:
1. Endianness
2. Размером структур.
3. Выравниванием структур.
4. Указателями.
5. Виртуальными функциями.

#pragma pack(push, 1)
struct A {
  int a, b;
  char x[4];
};
#pragma pack(pop)

reinterpret_cast<char*>(A);  // Законно.

reinterpret_cast<int*>(long long*);  // Бесполезен из-за endianness.

static_cast<int*>(void*); 

#include <iostream>


// 1       2       3       4
// 1       2       3       4
// 1       2       3       4
// 1       2       3       4
void pattern_1(int n)
{
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= n)
    {
      std::cout << j << "\t";
      j++;
    }
    i++;
    std::cout << std::endl;
  }
}

// 4       3       2       1
// 4       3       2       1
// 4       3       2       1
// 4       3       2       1
void pattern_2(int n)
{
  int i = n;
  while (i > 0)
  {
    int j = n;
    while (j > 0)
    {
      std::cout << j-- << "\t";
    }
    i--;
    std::cout << std::endl;
  }
}

// 1       2       3
// 4       5       6
// 7       8       9
void pattern_3(int n)
{
  int count = 1;
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= n)
    {
      std::cout << count++ << "\t";
      j++;
    }
    i++;
    std::cout << std::endl;
  }
}

// *
// *       *
// *       *       *
// *       *       *       *
void pattern_triangle1()
{
  int n;
  std::cin >> n;

  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= i)
    {
      std::cout << "*\t";
      j++;
    }
    i++;
    std::cout << std::endl;
  }
}

// 1
// 2       3
// 4       5       6
// 7       8       9       10
void pattern_triangle2()
{
  int count = 1;
  int n;
  std::cin >> n;

  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= i)
    {
      std::cout << count++ << "\t";
      j++;
    }
    i++;
    std::cout << std::endl;
  }
}

// 1
// 2       3
// 3       4       5
// 4       5       6       7
void pattern_triangle3()
{
  int n;
  std::cin >> n;

  int i = 1;
  while (i <= n)
  {
    int j = 1;
    int count = i;
    while (j <= i)
    {
      std::cout << count++ << "\t";
      j++;
    }
    i++;
    std::cout << std::endl;
  }
}

// 1
// 2       1
// 3       2       1
// 4       3       2       1
void pattern_triangle4()
{
  int n;
  std::cin >> n;

  int i = 1;
  while (i <= n)
  {
    int j = i;
    int count = i;
    while (j > 0)
    {
      std::cout << j-- << "\t";
    }
    i++;
    std::cout << std::endl;
  }
}

// A       A       A
// B       B       B
// C       C       C
void pattern_4()
{
  int n;
  std::cin >> n;
  int row = 1;

  while (row <= n)
  {
    int col = 1;
    while (col <= n)
    {
      char ch = 'A' + row - 1;
      std::cout << ch << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A       B       C
// A       B       C
// A       B       C
void pattern_5()
{
  int n;
  std::cin >> n;
  int row = 1;

  while (row <= n)
  {
    int col = 1;
    while (col <= n)
    {
      char chTemp = 'A' + col - 1;
      std::cout << chTemp << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A       B       C
// D       E       F
// G       H       I
void pattern_6()
{
  int n;
  std::cin >> n;
  int row = 1;

  char ch = 'A';
  while (row <= n)
  {
    int col = 1;
    while (col <= n)
    {
      std::cout << ch++ << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A       B       C
// B       C       D
// C       D       E
void pattern_7()
{
  int n;
  std::cin >> n;
  int row = 1;

  while (row <= n)
  {
    int col = 1;
    char ch = 'A' + row;
    while (col <= n)
    {
      char chTemp = ch + col - 2;
      std::cout << chTemp << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A
// B       B
// C       C       C
// D       D       D       D
void pattern_triangle5()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int col = 1;
    while (col <= row)
    {
      char ch = 'A' + row - 1;
      std::cout << ch << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A
// B       C
// D       E       F
// G       H       I       J
void pattern_triangle6()
{
  int n;
  std::cin >> n;

  int row = 1;
  char ch = 'A';
  while (row <= n)
  {
    int col = 1;
    while (col <= row)
    {
      std::cout << ch++ << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// A
// B       C
// C       D       E
// D       E       F       G
void pattern_triangle7()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int col = 1;
    while (col <= row)
    {
      char ch = 'A' + row + col - 2;
      std::cout << ch << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// D
// C       D
// B       C       D
// A       B       C       D
void pattern_triangle8()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int col = 1;
    char ch = 'A' + n - row;
    while (col <= row)
    {
      // char ch = 'A' + n + col - row - 1;
      std::cout << ch++ << "\t";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

//    *
//   **
//  ***
// ****
void pattern_8()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int spaces = n - row;
    int col = 1;
    while (spaces)
    {
      std::cout << " ";
      spaces--;
    }
    while (col <= row)
    {
      std::cout << "*";
      col++;
    }
    row++;
    std::cout << std::endl;
  }
}

// ****
// ***
// **
// *
void pattern_triangle9()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int col = n - row + 1;
    while (col)
    {
      std::cout << '*';
      col--;
    }
    row++;
    std::cout << std::endl;
  }
}

// ****
//  ***
//   **
//    *
void pattern_9()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int col = n - row + 1;
    int spaces = n - col;
    while (spaces)
    {
      std::cout << ' ';
      spaces--;
    }
    while (col)
    {
      std::cout << '*';
      col--;
    }
    row++;
    std::cout << std::endl;
  }
}

// 1       1       1       1
//         2       2       2
//                 3       3
//                         4
void pattern_10()
{
  int n;
  std::cin >> n;

  int row = 1;
  while(row <= n)
  {
    int col = n - row + 1;
    int spaces = n - col;
    while (spaces)
    {
      std::cout << " \t";
      spaces--;
    }
    while (col)
    {
      std::cout << row << "\t";
      col--;
    }
    row++;
    std::cout << std::endl;
  }
}

//                         1
//                 2       2
//         3       3       3
// 4       4       4       4
void pattern_11()
{
  int n;
  std::cin >> n;

  int row = 1;
  while(row <= n)
  {
    int spaces = n - row;
    int col = n - spaces;
    while (spaces)
    {
      std::cout << " \t";
      spaces--;
    }
    while (col)
    {
      std::cout << row << "\t";
      col--;
    }
    row++;
    std::cout << std::endl;
  }
}

// 1       2       3       4
//         2       3       4
//                 3       4
//                         4
void pattern_12()
{
  int n;
  std::cin >> n;

  int row = 1;
  while(row <= n)
  {
    int col = n - row + 1;
    int spaces = n - col;
    while (spaces)
    {
      std::cout << " \t";
      spaces--;
    }
    while (col)
    {
      int val = (n - col + 1);
      std::cout << val << "\t";
      col--;
    }
    row++;
    std::cout << std::endl;
  }
}

//                                 1
//                         1       2       1
//                 1       2       3       2       1
//         1       2       3       4       3       2       1
// 1       2       3       4       5       4       3       2       1
void pattern_13()
{
  int n;
  std::cin >> n;

  int row = 1;
  while (row <= n)
  {
    int spaces = n - row;
    int col = 1;
    while (spaces)
    {
      std::cout << " \t";
      spaces--;
    }
    while (col <= row)
    {
      std::cout << col << "\t";
      col++;
    }
    int start = row - 1;
    while (start)
    {
      std::cout << start-- << "\t";
    }
    row++;
    std::cout << std::endl;
  }
}


// 1       2       3       4       5       5       4       3       2       1
// 1       2       3       4       *       *       4       3       2       1
// 1       2       3       *       *       *       *       3       2       1
// 1       2       *       *       *       *       *       *       2       1
// 1       *       *       *       *       *       *       *       *       1
void pattern_14()
{
  int n = 5;

  int row = 1;
  while (row <= n)
  {
    int col1 = n - row + 1;
    int num = 1;
    int col2 = (row - 1) * 2;
    int col3 = n;
    while (col1)
    {
      std::cout << num++ << "\t";
      col1--;
    }
    while (col2)
    {
      std::cout << "* \t";
      col2--;
    }
    while (--num)
    {
      std::cout << num << "\t";
    }
    std::cout << std::endl;
    row++;
  }


}

int main()
{
  // pattern_1(4);
  // pattern_2(4);
  // pattern_3(3);
  // pattern_triangle1();
  // pattern_triangle2();
  // pattern_triangle3();
  // pattern_triangle4();
  // pattern_4();
  // pattern_5();
  // pattern_6();
  // pattern_7();
  // pattern_triangle5();
  // pattern_triangle6();
  // pattern_triangle7();
  // pattern_triangle8();
  // pattern_8();
  // pattern_triangle9();
  // pattern_9();
  // pattern_10();
  // pattern_11();
  // pattern_12();
  // pattern_13();
  pattern_14();
}
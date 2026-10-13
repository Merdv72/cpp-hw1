/*На складе радиоактивных отходов есть 5 этажей, на каждом из которых 5 комнат и
в каждой 5 контейнеров(везде нумерация с 0) На вход подаётся название команды и
параметры в зависимости от них: check a b c - проверить, сколько кг отходов
лежит в конейтнере c в команте b на этаже а. put a b c k t - положить  в
конейтнер c в команте b на этаже а k кг отходов типа t. Если тип - A или B, то
их можно хранить только на 4 и 5 этажах соответственно. Если тип - число, то
можно хранить на этаже, номер которго не меньше этого числа, т.е. 1 - на 1, 2,
3, 2 - на 2, 3, 3 - только на 3. Изменять кг в контейнерах нельзя - они
запечатываются и не вскрываются. Если попробовать положить в запечатанный
контейнер отходы, обратиться по несуществующему индексу или ввести неизвестную
команду - запрет доступа и выход из программы. int*** нужен, чтобы хранить
трёхмерный массив без траты дополнительной памяти через new. void* нужен, чтобы
хранить все типы в одном месте, без жесткого разграничения*/

#include <cstring>
#include <iostream>

int main() {
  const int type_1 = 1;
  const int type_2 = 2;
  const int type_3 = 3;
  const char type_A = 'A';
  const char type_B = 'B';
  const void* type[5] = {&type_1, &type_2, &type_3, &type_A, &type_B};
  int*** quantity = new int**[5]();
  int a;
  int b;
  int c;
  int k;
  char t;
  char func[32] = "";
  std::cin >> func;
  while (std::strcmp(func, "end")) {
    if (!std::strcmp(func, "put")) {
      std::cin >> a >> b >> c >> k >> t;
      if (a < 0 || a > 4 || b < 0 || b > 4 || c < 0 || c > 4 ||
          (quantity[a] && quantity[a][b] && quantity[a][b][c] != 0)) {
        std::cout << "access disabled";
        break;
      }
      bool found = false;
      for (int i = 0; i < 5 && !found; ++i) {
        if (i < 3) {
          found = (t - '0' <= *static_cast<const int*>(type[i]));
        } else {
          found = (t == *static_cast<const char*>(type[i]));
        }
      }
      if (!found) {
        std::cout << "access disabled";
        break;
      }
      if (!quantity[a]) {
        quantity[a] = new int*[5]();
      }
      if (!quantity[a][b]) {
        quantity[a][b] = new int[5]();
      }
      quantity[a][b][c] = k;
    } else if (!std::strcmp(func, "check")) {
      std::cin >> a >> b >> c;
      if (a < 0 || a > 4 || b < 0 || b > 4 || c < 0 || c > 4) {
        std::cout << "access disabled";
        break;
      }
      if (quantity[a] && quantity[a][b]) {
        std::cout << quantity[a][b][c] << std::endl;
      } else {
        std::cout << 0 << std::endl;
      }
    } else {
      std::cout << "access disabled";
      break;
    }
    std::cin >> func;
  }

  for (int i = 0; i < 5; ++i) {
    if (quantity[i]) {
      for (int j = 0; j < 5; ++j) {
        delete[] quantity[i][j];
      }
    }
    delete[] quantity[i];
  }
  delete[] quantity;
}
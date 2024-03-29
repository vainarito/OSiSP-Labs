# dirwalk

**dirwalk** - это простая командная утилита для рекурсивного обхода директории и вывода списка путей к файлам и директориям в заданной директории. Утилита предоставляет возможность фильтровать и сортировать результаты в соответствии с заданными опциями.

## Как работает dirwalk

dirwalk работает следующим образом:

1. Утилита принимает один аргумент командной строки - путь к директории, которую необходимо обойти. Если аргумент не указан, будет использоваться текущая директория.

2. После получения пути, утилита анализирует заданные опции командной строки. Доступные опции:

   - **`-l`**: Включает вывод символических ссылок.
   - **`-f`**: Включает вывод обычных файлов.
   - **`-d`**: Включает вывод директорий.
   - **`-s`**: Включает сортировку результатов по алфавиту.
   
   Если не указана ни одна опция, будут выведены все типы файлов.

3. Утилита рекурсивно обходит указанную директорию и сохраняет пути к файлам и директориям, соответствующим заданным опциям.

4. По окончании обхода директории, утилита выводит список путей в соответствии с заданными опциями. Если включена опция **`-s`**, результаты будут отсортированы по алфавиту.

## Как использовать dirwalk

1. Компиляция программы:
gcc -o dirwalk main.c dirwalk.c

2. Запуск утилиты:
./dirwalk [OPTIONS] [DIRECTORY]

Здесь **`[OPTIONS]`** - одна или несколько опций командной строки **`-l`**, **`-f`**, **`-d`**, **`-s`**, а **`[DIRECTORY]`** - путь к директории, которую необходимо обойти. Если **`[DIRECTORY]`** не указан, будет использоваться текущая директория.

3. Примеры использования:

- Вывод всех файлов и директорий в текущей директории:
  ```
  ./dirwalk
  ```

- Вывод только директорий в указанной директории:
  ```
  ./dirwalk -d /path/to/directory
  ```

- Вывод символических ссылок и сортировка результатов:
  ```
  ./dirwalk -ls /path/to/directory
  ```

## Примечания

- Утилита поддерживает русскую локаль для правильной сортировки файлов и директорий по алфавиту на основе правил русского языка.

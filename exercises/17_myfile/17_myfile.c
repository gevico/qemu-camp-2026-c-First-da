#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_elf_type(uint16_t e_type) {
  const char *type_str;
  switch (e_type) {
    // ET_NONE  → Unknown / No file type
    // ET_REL   → Relocatable
    // ET_EXEC  → Executable
    // ET_DYN   → Shared Object/PIE
    // ET_CORE  → Core file
    case (ET_NONE) :
      {
        type_str = "Unknown";
        break;
      }
    case (ET_REL):
      {
        type_str = "Relocatable";
        break;
      }
    case (ET_EXEC):
      {
        type_str = "Executable";
        break;
      }
    case (ET_DYN):
      {
        type_str = "Shared Object/PIE";
        break;
      }    
    case (ET_CORE):
      {
        type_str = "Core file";
        break;
      }
  }
  printf("ELF Type: %s (0x%x)\n", type_str, e_type);
}

int main(int argc, char *argv[]) {
  char filepath[2][256] = {
    "./17_myfile.o",
    "./17_myfile",
  };

  int fd;
  Elf64_Ehdr ehdr;
  fd = open(filepath[0], O_RDONLY);
  if (fd < 0)
    {
      perror("open");
      exit(1);
    }  

  int read_num;
  read_num = read(fd, &ehdr, sizeof(ehdr));
  if (read_num < 0)
  {
      perror("read");
      exit(1);
  }

  print_elf_type(ehdr.e_type);
  close(fd);



  fd = open(filepath[1], O_RDONLY);
  if (fd < 0)
    {
      perror("open");
      exit(1);
    }  

  read_num = read(fd, &ehdr, sizeof(ehdr));
  if (read_num < 0)
  {
      perror("read");
      exit(1);
  }

  print_elf_type(ehdr.e_type);
  close(fd);
  return 0;
}

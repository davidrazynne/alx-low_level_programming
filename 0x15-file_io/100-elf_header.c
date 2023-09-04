#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <elf.h>

void print_version(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);

/**
 *

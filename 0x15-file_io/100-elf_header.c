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
 * check_elf – This fxn will check whether a file is an ELF file
 *
 * @e_ident: an address to an array that has ELF magic numbers
 *
 * Description: file is not an ELF file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int _index;

	for (_index = 0; _index < 4; _index++)
	{
		if (e_ident[_index] != 127 &&
		    e_ident[_index] != 'E' &&
		    e_ident[_index] != 'L' &&
		    e_ident[_index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic – this fxn will print the ELF header magic numbers
 * @e_ident: an address to an array that has ELF magic numbers
 * Description: spaces separate the Magic numbers
 */
void print_magic(unsigned char *e_ident)
{
	int _index;

	printf(" Magic: ");

	for (_index = 0; _index < EI_NIDENT; _index++)
	{
		printf("%02x", e_ident[_index]);

		if (_index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class – this will print the ELF header class
 * @e_ident: an address to an array that has ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data – this inturn will print the ELF header data
 * @e_ident: an address to an array that has ELF magic numbers
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - ELF header version.
 * @e_ident: an address to an array that has ELF class
 *
 */
void print_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - OS/ABI ELF header.
 * @e_ident: array with ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - ELF header ABI version
 * @e_ident: address for array with ELF ABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - ELF header type.
 * @e_type: type of ELF
 * @e_ident: address for an array with ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry – this fxn will print the beginning(entry point) of ELF header
 * @e_entry: The address of the ELF beginning (entry point)
 * @e_ident: an address to an array that has ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf – fxn to close ELF file.
 * @elf: fd of the ELF file.
 *
 * Description: file closure failss - exit code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - show information in the ELF header at the beginning of ELF file
 *
 * @argc: The count of arguments given to the program
 * @argv: array of pointers for arguments
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File/function fails - exit code 98
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int e, r;

	e = open(argv[1], O_RDONLY);
	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(e);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(e, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(e);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(e);
	return (0);
}

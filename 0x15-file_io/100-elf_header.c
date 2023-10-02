#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define ELF_MAGIC_SIZE 4

typedef struct
{
	unsigned char ident[ELF_MAGIC_SIZE];
	uint8_t class;
	uint8_t data;
	uint8_t version;
	uint8_t osabi;
	uint8_t abiversion;
	uint8_t pad[7];
	uint16_t type;
	uint16_t machine;
	uint32_t version2;
	uint64_t entry;
	uint64_t phoff;
	uint64_t shoff;
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
}
ElfHeader;

void print_elf_header(ElfHeader header)
{
	printf("Magic:   %02x %02x %02x %02x\n",
	       header.ident[0], header.ident[1], header.ident[2], header.ident[3]);
	printf("Class:                             %s\n",
	       (header.class == 1) ? "ELF64" : "ELF32");
	printf("Data:                              %s\n",
	       (header.data == 1) ? "duo complement" : "Invalid encoding");
	printf("Version:                           %d (current)\n", header.version);
	printf("OS/ABI:                            %d\n", header.osabi);
	printf("ABI Version:                       %d\n", header.abiversion);
	printf("Type:                              0x%x\n", header.type);
	printf("Entry point address:               0x%lx\n", header.entry);
}

int main(int argc, char *argv[])
{	

	if (argc != 2)
	{
		fprintf(stderr, "Usage is: %s elf_filename\n", argv[0]);
		return (98);
	}

	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);

	if (fd == -1)

	{
		perror("Error ecountered while opening file");
		return (98);
	}

	ElfHeader header;
	ssize_t bytes_read = read(fd, &header, sizeof(ElfHeader));

	if (bytes_read != sizeof(ElfHeader) || memcmp(header.ident, "\x7F""ELF", ELF_MAGIC_SIZE) != 0)

	{
		fprintf(stderr, "%s not ELF file.\n", filename);
		return (98);
	}

	print_elf_header(header);

	close(fd);
	return (0);
}

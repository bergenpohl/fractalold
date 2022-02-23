#include "fractal.h"

int	save_to_bitmap_file(t_session *s)
{
	int	fd;
	int	padding_size;
	
	fd = open("./results/fractal.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	
	padding_size = (4 - (s->img.width * s->img.bits_per_pixel / 8) % 4) % 4;

	bitmap_file_header(s, padding_size, fd);
	bitmap_info_header(s, fd);
	bitmap_pixel_data(s, padding_size, fd);

	close(fd);
	return (0);
}

int	bitmap_file_header(t_session *s, int padding_size, int fd)
{
	unsigned char	*header;
	int				filesize;

	header = (unsigned char *)ft_calloc(BMP_FILE_HEADER_SIZE, sizeof(unsigned char));
	if (header == NULL)
		return (-1);
	filesize = BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE + (s->img.bits_per_pixel / 8 * s->img.width + padding_size) * s->img.height;
	header[0] = (unsigned char)0x42;
	header[1] = (unsigned char)0x4D;
	header[2] = (unsigned char)(filesize);
	header[3] = (unsigned char)(filesize >> 8);
	header[4] = (unsigned char)(filesize >> 16);
	header[5] = (unsigned char)(filesize >> 24);
	header[10] = (unsigned char)(BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE);
	write(fd, header, BMP_FILE_HEADER_SIZE);
	free(header);
	return (0);
}

int bitmap_info_header(t_session *s, int fd)
{
	unsigned char	*header;

	header = (unsigned char *)ft_calloc(BMP_INFO_HEADER_SIZE, sizeof(unsigned char));
	header[0] = BMP_INFO_HEADER_SIZE;
	header[4] = (unsigned int)(s->img.width);
	header[5] = (unsigned int)(s->img.width >> 8);
	header[6] = (unsigned int)(s->img.width >> 16);
	header[7] = (unsigned int)(s->img.width >> 24);
	header[8] = (unsigned int)(s->img.height);
	header[9] = (unsigned int)(s->img.height >> 8);
	header[10] = (unsigned int)(s->img.height >> 16);
	header[11] = (unsigned int)(s->img.height >> 24);
	header[12] = (unsigned int)(1);
	header[14] = (unsigned int)s->img.bits_per_pixel;
	write(fd, header, BMP_INFO_HEADER_SIZE);
	free(header);
	return (0);
}

int bitmap_pixel_data(t_session *s, int padding_size, int fd)
{
	long			i;
	unsigned char	padding[3];
	long			count;
	
	count = 0;
	i = s->img.height - 1;
	while (i >= 0)
	{
		write(fd, s->img.mem + (s->img.size_line * i), s->img.size_line);
		count += s->img.size_line;
		write(fd, padding, padding_size);
		count += padding_size;
		--i;
	}
	return (0);
}

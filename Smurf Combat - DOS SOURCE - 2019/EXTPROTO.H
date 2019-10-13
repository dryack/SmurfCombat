
extern int blockade(char *filename, size_t bufsize);
extern int calc_crc_file(char *filename, long offset, size_t bufsize, long *crcptr);
extern long blk_fsize(FILE *);

/* ------ chkblk.c  ------ */

extern unsigned long chkblk(char *buffer, int size, unsigned long init);

/* ------ blkade1.c  ------ */

extern char *get_blk_err_msg( int );

/* ------ blkade2.c  ------ */

extern unsigned long chksum8( char *, int , unsigned long);

/* ------ blkade3.c  ------ */

extern unsigned long chksum32( char *, int , unsigned long);

/* ------ blkade4.c  ------ */

extern unsigned long crc32(char *buffer, int size, unsigned long init);
extern int showcrc( long crc);

/* ------    end     ------ */


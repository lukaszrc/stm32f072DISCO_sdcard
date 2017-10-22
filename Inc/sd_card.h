#ifndef _SDCARD
#define _SDCARD

 // Summary: The format of an R1 type response
 // Description: This union represents different ways to access an SD card R1 type response packet.
 typedef union
 {
     unsigned char     byte;                 // Byte-wise access
     // This structure allows bitwise access of the response
     struct
     {
         unsigned     IN_IDLE_STATE:1;       // Card is in idle state
         unsigned     ERASE_RESET:1;         // Erase reset flag
         unsigned     ILLEGAL_CMD:1;         // Illegal command flag
         unsigned     CRC_ERR:1;             // CRC error flag
         unsigned     ERASE_SEQ_ERR:1;       // Erase sequence error flag
         unsigned     ADDRESS_ERR:1;         // Address error flag
         unsigned     PARAM_ERR:1;           // Parameter flag
         unsigned     B7:1;                  // Unused bit 7
     }bits;
 } SD_RESPONSE;

typedef struct {                        // struct to describe sd card
     unsigned         ok:1;        // card is initialized or status is OK
     unsigned         wp:1;        // card is write protected
     unsigned         cd:1;        // card is detected
     unsigned         hc:1;        // card is high capacity
     unsigned         v1:1;        // card is version 1
     unsigned         no_idle:1;    // card did not GO_STATE_IDLE
     unsigned         no_opc:1;     // send_op_cond timed out
     unsigned         no_ocr:1;    // send_ocr command timed out
     unsigned         no_pup:1;    // card not powered up after init request
     unsigned         no_csd:1;     // send_CSD command timed out
     unsigned        no_w:1;        // write did not complete (timed out)
     unsigned         csd_err:1;     // card did not issue 0xFE at start of CSD data
     unsigned        w_err:1;    // write error (command not accepted)
     unsigned         r_err:1;    // read error
     unsigned        d_err:1;    // data error (data not accepted)
     unsigned        pad:2;
     unsigned int    timeout;    // timeout value when ops timeout
     unsigned long    size;        // card size in 512kbyte blocks (ie actual capacity is 1000 * m_size / 2 bytes)
 } SD_CARD;


int init_sdcard(SD_CARD *, SD_RESPONSE *);

#endif

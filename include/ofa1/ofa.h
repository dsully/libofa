/* ------------------------------------------------------------------

   libofa -- the Open Fingerprint Architecture library

   Copyright (C) 2006 MusicIP Corporation
   All rights reserved.

-------------------------------------------------------------------*/
#ifndef _OFA_H_
#define _OFA_H_

#ifdef __cplusplus
extern "C"
{
#endif

/** Indicates data in big endian byte order */
#define OFA_LITTLE_ENDIAN (0)
/** Indicates data in little endian byte order */
#define OFA_BIG_ENDIAN (1)

/**
 * Retrieve the version of the library
 *
 * @param major a pointer to int
 * @param minor a pointer to int
 * @param rev a pointer to int
 */
void ofa_get_version(int *major, int *minor, int *rev);

/**
 * Top level function generating the fingerprint.
 *
 * This is the simplest interface required to generate fingerprints.
 * examples/protocol.h defines some higher level classes which can be connected
 * to codecs in various formats for a higher level API
 * 
 * @param data a buffer of 16-bit samples in interleaved format (if stereo),
 *  i.e. L,R,L,R, etc. This buffer is destroyed during processing. Ideally,
 *  this buffer should contain the entire song to be analyzed, but the process
 *  will only need the first 2min + 10sec + any silence prepending the actual
 *  audio. Since the precise silence interval will only be known after a couple
 *  of processing steps, the caller must make adequate allowance for this.
 *  Caveat emptor.
 * @param byteOrder \a OFA_LITTLE_ENDIAN, or \a OFA_BIG_ENDIAN - indicates the
 *  byte order of the data being passed in.
 * @param size the size of the buffer, in number of samples.
 * @param sRate the sample rate of the signal. This can be an arbitrary rate,
 *  as long as it can be expressed as an integer (in samples per second). If
 *  this is different from 44100, rate conversion will be performed during
 *  preprocessing, which will add significantly to the overhead.
 * @param stereo 1 if there are left and right channels stored, 0 if the data
 *  is mono
 * @return On success, a valid text representation of the fingerprint is
 *  returned. The returned buffer will remain valid until the next call to
 *  ofa_create_print.
 *
 * @note NOTE THAT THE PASSED IN DATA MAY BE BYTE SWAPPED DURING THE METHOD.
 * ASSUME THAT DATA IN THE INPUT BUFFER IS DESTROYED AS A SIDE-EFFECT OF 
 * CALLING THIS FUNCTION
 */ 
const char *ofa_create_print(unsigned char* samples, int byteOrder, long size, int sRate, int stereo);

#ifdef __cplusplus
}
#endif

#endif

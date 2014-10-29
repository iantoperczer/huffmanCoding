#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>
#include <bitset>

using namespace std;

/** A class for reading bits (and ints) from an istream. **/
class BitInputStream {

private:
  /** The istream to delegate to. **/
  istream& in;
  /** The buffer of bits. **/
  char buf;
  /** TODO bitset<8> buf; **/
  /** The bit buffer index. **/
  int bufi;

public:
  /** Initialize a BitInputStream object, given an istream. **/
  BitInputStream(istream& s) : in(s), buf(0), bufi(8) { }
  /** TODO BitInputStream(istream& s) : in(s), bufi(8) { } **/

  /** Read the next bit from the bit buffer.
   *  If the bit buffer is currently empty,
   *  fill the bit buffer by reading a char from the istream first.
   *  Return the bit read as the least signficant bit of an int.
   *  Return -1 on EOF.
   *  This must be consistent with BitOutputStream::writeBit(), in terms
   *  of ordering of bits in the stream.
   */
  int readBit();

  /** Read a byte from the ostream.
   *  Return -1 on EOF.
   *  This function doesn't touch the bit buffer.
   *  The client has to manage interaction between reading bits
   *  and reading bytes.
   */
  int readByte();

  /** Read a non-negative int from the ostream.
   *  Return -1 on EOF.
   *  This function doesn't touch the bit buffer.
   *  The client has to manage interaction between reading bits
   *  and reading ints.
   */
  int readInt();
};

#endif /** BITINPUTSTREAM_HPP **/

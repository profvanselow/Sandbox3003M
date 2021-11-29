#pragma once
class Accumulator {
 private:
  int m_value;

 public:
  Accumulator() { m_value = 0; }
  void add(int value) { m_value += value; }

  // Make the reset() function a friend of this class
  friend void reset(Accumulator& accumulator);
};

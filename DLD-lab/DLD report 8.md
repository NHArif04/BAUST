## **Experiment No:** 8

## **Name of the Experiment:** Design and Implementation of a Full Adder Circuit Using a Decoder

## **Objectives:**
- To understand the operation and significance of a full adder in digital circuits.
- To design and implement a full adder circuit using a decoder and other essential components.
- To validate the functionality of the full adder through practical experimentation.

## **Apparatus:**
- Breadboard
- Connecting wires
- LEDs and resistors
- Power supply
- ICs

## **Components:**
- Decoder IC (e.g., 3-to-8 line decoder)
- Logic gates (AND, OR, XOR, NOT)
- Integrated circuits (ICs)

## **Introduction:**

## **Theory:**
### **Decoder:**
A decoder is a combinational logic circuit that converts a binary input into one of its possible output lines. In this experiment, a 3-to-8 line decoder will be used. It has 3 input lines (A, B, C) and 8 output lines (Y0 to Y7). The output line corresponding to the binary input is activated.

### **Full Adder:**
A full adder is a fundamental digital circuit used in arithmetic operations, particularly for adding binary numbers. It takes three binary inputs: A, B, and Carry In (Cin) and produces two outputs: Sum (S) and Carry Out (Cout). The truth table for a full adder is as follows:

|Decoder| A | B | Cin | Sum | Cout |
|-----|----|----|-----|-----|------|
|D0| 0 | 0 | 0   | 0   | 0    |
|D1| 0 | 0 | 1   | 1   | 0    |
|D2| 0 | 1 | 0   | 1   | 0    |
|D3| 0 | 1 | 1   | 0   | 1    |
|D4| 1 | 0 | 0   | 1   | 0    |
|D5| 1 | 0 | 1   | 0   | 1    |
|D6| 1 | 1 | 0   | 0   | 1    |
|D7| 1 | 1 | 1   | 1   | 1    |


**Procedure:**
1. Set up the breadboard for the experiment.
2. Design the full adder circuit using a 3-to-8 line decoder and other necessary logic gates based on the truth table.
3. Implement the circuit on the breadboard, integrating the decoder and ICs.
4. Input binary values for A, B, and Carry In.
5. Observe the LED outputs, which represent the Sum and Carry Out.
6. Validate the circuit's functionality by performing addition with various input combinations.

**Results:**
The full adder circuit, designed and implemented using a 3-to-8 line decoder, accurately produced Sum and Carry Out outputs for different binary inputs. The LED outputs correctly reflected the results of binary addition.

**Conclusion:**
This experiment effectively demonstrated the design and practical application of a full adder circuit using a decoder. By simplifying the circuit with a decoder, the addition of binary numbers became more efficient. This experiment solidified our understanding of the full adder's operation and its significance in digital arithmetic.

---

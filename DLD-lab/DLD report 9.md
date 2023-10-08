### **Experiment No:** 09

### **Name of the Experiment:** Study and Implementation of Flip-Flops (S-R, J-K, T, D, Dual J-K)

### **Apparatus:**
- Breadboard
- Connecting wires
- Trainer Board
- Power supply

### **Components:**
- Logic gates (AND, OR, NOT)
- Flip-flop ICs (74LS76, 74LS74)
- Integrated circuits (ICs)

### **Introduction:**
Flip-flops are fundamental digital circuits that store binary information and are widely used in sequential logic. This experiment aims to study and implement various types of flip-flops, including S-R, J-K, T, D, and Dual J-K flip-flops, to understand their characteristics and applications.

### **Theory:**

**S-R Flip-Flop:**
The S-R (Set-Reset) flip-flop has two inputs, S (Set) and R (Reset). When S=1 and R=0, the flip-flop sets to 1 (Q=1). When S=0 and R=1, it resets to 0 (Q=0). S=0 and R=0 are forbidden states, and S=1 and R=1 can lead to unpredictable behavior.

**J-K Flip-Flop:**
The J-K flip-flop has two inputs, J (Jack) and K (King). When J=1 and K=0, it toggles the output state (Q=Q'). When J=0 and K=1, it toggles the output but complemented (Q=Q'). When J=0 and K=0, it maintains the current state. J=1 and K=1 are toggle states.

**T Flip-Flop:**
The T (Toggle) flip-flop has one input, T. When T=1, it toggles the output state (Q=Q'). When T=0, it maintains the current state.

**D Flip-Flop:**
The D (Data) flip-flop has one input, D. It stores the input value at the rising (positive) edge of the clock signal.

**Dual J-K Flip-Flop:**
The Dual J-K flip-flop contains two J-K flip-flops in a single IC package. It shares the same clock signal and operates independently.

### **Procedure:**
1. Set up the breadboard and power supply.
2. Design and implement S-R, J-K, T, D, and Dual J-K flip-flop circuits using appropriate ICs and logic gates.
3. Input various combinations of control signals and clock pulses.
4. Observe the LED outputs and the behavior of each flip-flop type.
5. Analyze the results and record observations.

### **Conclusion:**
This experiment explored the characteristics and applications of different flip-flop types, including S-R, J-K, T, D, and Dual J-K flip-flops. By studying their behavior and implementing practical circuits, we gained insight into their utility in sequential logic circuits and data storage applications. Understanding flip-flops is fundamental for building sequential digital systems.
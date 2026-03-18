# **CSE 4283 / 6283 – Software Testing and Quality Assurance**

## **Assignment 2 – Project Report (BMI Application)**

---

## **Student Information**

* **Name:** Charles Lenson
* **NetID:** (Enter Your NetID)
* **GitHub Username:** (Enter Your GitHub Username)

---

## **1. Overview**

This project implements a Body Mass Index (BMI) calculator using a Test-Driven Development (TDD) approach. The application allows users to input their height and weight and returns both the BMI value and its corresponding category. Unit tests were written to verify correctness and ensure reliability of the program.

---

## **2. Functions and Associated Tests**

### **Function 1: `calculate_bmi(weight, feet, inches)`**

**Description:**
This function calculates BMI using weight (in pounds) and height (in feet and inches). It converts height into total inches and applies the BMI formula:
[
BMI = \frac{weight}{height^2} \times 703
]
The result is rounded to one decimal place.

**Test Cases:**

* Valid input: `calculate_bmi(150, 5, 6)` → Expected: `24.2`
* Edge case: small height values
* Error cases (optional): zero or negative values

---

### **Function 2: `get_category(bmi)`**

**Description:**
This function takes a BMI value and returns the corresponding category:

* Underweight: BMI < 18.5
* Normal weight: 18.5–24.9
* Overweight: 25–29.9
* Obese: ≥ 30

**Test Cases:**

* `18.4` → Underweight
* `18.5` → Normal weight (boundary)
* `24.9` → Normal weight (upper boundary)
* `25.0` → Overweight
* `29.9` → Overweight
* `30.0` → Obese

---

## **3. Boundary Testing Technique**

The testing technique used is **Boundary Value Analysis (BVA)**.
This technique focuses on testing values at and around the boundaries where program behavior changes.

**Why used:**

* Most errors occur at boundary values
* Ensures correctness at category transitions

**Boundaries tested:**

* Just below boundary: 18.4
* At boundary: 18.5
* Just above boundary: 25.0

---

## **4. Boundary Shift (0.1 Error)**

The lower boundary for “Normal weight” was intentionally shifted from **18.5 to 18.6**:

```python
elif bmi >= 18.6 and bmi <= 24.9:
    return "Normal weight"
```

This creates an error where a BMI of **18.5 is incorrectly classified**.

*(Insert screenshot of this code in your submission)*

---

## **5. Did Test Cases Catch the Error?**

Yes, the test cases successfully detected the boundary shift error.

**Reason:**

* A test case checks BMI = 18.5
* Expected result: “Normal weight”
* Actual result (after shift): “Underweight”

This mismatch causes the test to fail, proving that boundary testing is effective in catching such issues.

---

## **6. Setup and Execution Instructions (Windows 10)**

### **Requirements:**

* Python 3.x installed
* Google Colab OR local Python environment

### **Download Link:**

* GitHub Repository: (Insert your GitHub link here)

---

### **Steps to Run (Local Machine):**

1. Download or clone the repository
2. Open Command Prompt
3. Navigate to project folder
4. Run the program:

   ```
   python main.py
   ```
5. Enter height and weight when prompted

---

### **Steps to Run Tests:**

```
python -m unittest test_bmi.py
```

---

### **Using Google Colab:**

1. Open Google Colab
2. Copy and paste the code into cells
3. Run each cell
4. View outputs

---

## **7. Screenshots of Correct Output**

Provide screenshots showing correct outputs for:

* Underweight (BMI < 18.5)
* Normal weight (18.5–24.9)
* Overweight (25–29.9)
* Obese (≥ 30)

*(Insert 4 screenshots here — one for each category)*

---

## **8. Conclusion**

This project demonstrates how TDD improves software quality by ensuring all functions are tested before deployment. Boundary Value Analysis helped identify critical edge cases, and the test suite successfully detected introduced errors such as boundary shifts. The application meets all requirements and produces accurate BMI classifications.

---


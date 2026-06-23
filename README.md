# ⏳ Advanced Age & Time Calculator

Welcome to my first Software Engineering project! This is a comprehensive C-based tool that calculates precise age, lifetime metrics, and calendar-specific details from a user's date of birth. 

Developed as part of my academic journey at **Shahjalal University of Science and Technology (SUST)**.

---

## 👤 Developer Profile

<h1>👨‍💻 <span style="color:#2196F3;">Raj Bhowmik</span></h1>

* **Department:** <code><span style="color:#00C853;"><b>Software Engineering (SUST)</b></span></code>
* **Batch:** <code>2025</code>
* **Project Milestone:** First standalone C project building a fully packaged Windows executable.

---

## 🚀 Features & Core Logic

* 🟩 **Precise Age Breakdown:** Calculates exact age in Years, Months, and Days.
* 🟦 **Lifetime Metrics:** Tracks total elapsed time since birth down to days, hours, minutes, and seconds.
* 🟪 **Zeller's Congruence:** Implements Zeller's mathematical formula to accurately determine the exact day of the week you were born.
* 🟨 **Next Birthday Countdown:** Dynamically calculates how many days are left until your next celebration.

---

## 🛠️ Tech Stack & Key Learnings

This project was a rollercoaster of fun, challenges, and intense debugging. Through the process of building, breaking, and refactoring this application, I learned several foundational concepts:

<blockquote>
  <h3>💡 What I Learned:</h3>
  <ul>
    <li>🧪 <b>Modular Programming:</b> Mastered organizing code into multiple <code>.c</code> and <code>.h</code> files, managing scopes, and compiling them together cleanly.</li>
    <li>⚡ <b>Ternary Operators:</b> Learned how to optimize code structures by substituting verbose <code>if-else</code> blocks with sleek <code>? :</code> conditional operators.</li>
    <li>📦 <b>Resource Compiling:</b> Discovered how to bundle raw C binaries with standard <code>.rc</code> (Windows Resource) scripts to package a standalone <code>.exe</code> with a custom branded application icon.</li>
    <li>🔧 <b>Advanced Debugging:</b> Navigated complex nested brackets, pointer logic, and time conversions. Leveraging AI resources constructively helped me identify code design flaws and refine my logical thinking.</li>
    <li>🐙 <b>Version Control:</b> Gained practical experience utilizing Git and GitHub more effectively for project tracking and codebase management.</li>
  </ul>
</blockquote>

---

## 💻 Compilation and Execution

To compile the modular source files along with the embedded custom icon script via MinGW, run the following commands in your terminal:

```bash
# 1. Compile the icon resource file
windres resource.rc -O coff -o resource.res

# 2. Compile and link all modular files into the final executable
gcc main.c "../Function files/functions.c" resource.res -o AgeCalculator.exe

# 3. Run the application
./AgeCalculator.exe

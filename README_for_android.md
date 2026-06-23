## 📱 How to Run on Android (Via Termux)

If you don't have a PC nearby, you can compile and run this application directly on your Android smartphone using **Termux**. This guide will show you how to automatically pull all the files into a single directory and run it flawlessly in 3 simple steps!

### 📥 Step 1: Install Termux
1. Download and install the Termux app from the [Google Play Store](https://play.google.com/store/apps/details?id=com.termux).
2. Open Termux on your phone.

### ⚙️ Step 2: Set Up the C Environment
Copy and paste this single command into Termux to update your environment and install the required compiler (`clang`) and version control tool (`git`):
```bash
pkg update && pkg upgrade -y && pkg install clang git -y

# 1. Clone the entire repository onto your phone
git clone <https://github.com/rajbhowmik-code/C-and-C-.git>

# 2. Move inside the project's root folder
cd age-calc-v

# 3. Create a fresh single directory named 'App' for execution
mkdir App

# 4. Copy the 3 main files from their separate locations into the 'App' folder
cp "Main files (age-calc-v)/main.c" "Function files/functions.c" "Function files/functions.h" App/

# 5. Move inside your newly created 'App' folder where all 3 files are now sitting together
cd App

# 6. Compile the files cleanly using the clang compiler
clang main.c functions.c -o AgeCalculator

# 7. Launch your App directly on your smartphone screen!
./AgeCalculator


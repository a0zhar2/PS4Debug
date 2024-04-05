# PS4Debug (Playstation 4 Process Debugger)

This is A0ZHAR's own fork of GiantPluto's version of PS4Debug. The PS4Debug Payload is a Userland-Mode Process Debugging Tool for the PlayStation 4 System. For now, it only supports system firmware **6.72**! 

But I am planning on adding support for the System Firmware: **5.05, 7.02, 7.5X, and 9.00**


## How to use the PS4Debug.bin Payload

<details>
<summary>See Instructions (English)</summary>
<br>

**Note: Ensure your computer and PS4 are connected to the same WiFi network**
1. **Download PS4Cheater Executable:**
   - Get it from [ctn123's repository](https://github.com/ctn123/PS4_Cheater/releases)
   - It's similar to Cheat Engine but for your PS4.
2. **Get PS4Debug:**
   - You can either build PS4Debug yourself (refer to **How to Build** Guide)
   - Or you can download the pre-built file from [here](https://github.com/a0zhar/ps4debug/releases).
3. **Prepare for Installation:**
   - Once you have PS4Cheater and the PS4Debug.bin file, proceed to the next step.
4. **Start Your PS4:**
   - Open the web browser and go to `https://gamerhack.github.io/`.
   - Use the recommended host.
5. **Enable Homebrew:**
   - After the page loads, select your firmware and run the latest GoldHen (Homebrew Enabler) Payload.
6. **Load PS4Debug:**
   - Run the `Bin Loader` payload.
   - Look for a notification indicating something like `Send payload to port 9021`.
7. **Send PS4Debug Payload:**
   - Ensure PS4Debug.bin is in the same folder as `send.bat` (for Windows) or `send.sh` (for Linux).
   - Manually change the IP address in the script to match your PS4's IP.
8. **Execute the Payload:**
   - **For Windows:** Run `send.bat`.
   - **For Linux:** Run `send.sh`.
9. **Confirm PS4Debug Loaded:**
   - When you see a notification on your PS4 saying `PS4Debug loaded!`, proceed.
10. **Setup PS4 Cheater:**
    - Open the PS4 Cheater program and enter your PS4's IP.
    - **IMPORTANT:** Press the `Refresh` button, not `Inject`.
11. **Ignore Misleading Message:**
    - The bottom label might say `Successfully injected`, ignore it.
12. **Start the Game:**
    - Launch the game you want to hack.
13. **Refresh PS4 Cheater:**
    - Once the game is running, press `Refresh` on PS4 Cheater.
14. **Select Game Executable:**
    - From the dropdown, choose `eboot.bin` (the game executable).
15. **Select Memory Sections:**
    - Tick the checkbox labeled `Select All` in the memory sections box.
16. **Search for Value:**
    - Enter a value to search for and you're ready to go.
</details>


## How to Build? (from source)
<details>
<summary>See Instructions (English)</summary>
<br>

**NOTE:** If you are using Windows you will need to have [WSL - Ubuntu terminal environment](https://ubuntu.com/desktop/wsl) installed!
This software allows you to have a Ubuntu terminal environment on Windows, and you need it to be able to build this Payload
1. **Pre-Requisites:**
   - If this is the first time that you are building an payload, then you'll need to have the Development Tools installed.<br>
     These include, `gcc`, `g++`, and `make`. To install them simply run following command's in the Terminal:
     - `sudo apt-get update`
     - `sudo apt-get -y install binutils gcc make`
   - Then simply reboot the Ubuntu Terminal/System
2. **Building the Payload with 1 simple command**
   - In the Ubuntu Terminal run `cd` + <*the path to the downloaded and extracted ps4debug foler*>
   - Then run `bash build.sh` and the shell script will do all the work for you
3. **Final!**
   - After running the shell script, you will see a new file called `ps4debug.bin` appear in the folder where the shell script is.
   - This is the compiled Payload (.bin) file!!!
</details>

---


### Credits/Special thanks too
- [GiantPluto](https://github.com/GiantPluto) - For porting the PS4Debug to PS4 FW 6.72
- [jogolden](https://github.com/jogolden) - For initially creating PS4Debug
- [ChendoChap](https://github.com/ChendoChap) - For his intial work till 5.05 and his guidance during 6.72 porting on ptrace
- [berkayylmao](https://github.com/berkayylmao)
- [2much4u](https://github.com/2much4u)
- [idc](https://github.com/idc)
- [zecoxao](https://github.com/zecoxao)
- [DeathRGH](https://github.com/DeathRGH) - For second PTrace Patch for PS4 (FW 6.72) [See Here](https://github.com/GiantPluto/ps4debug/blob/457c2bf5468329e68a272b5f1e1ab88957f5f2d8/installer/source/installer.c#L53)

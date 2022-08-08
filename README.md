# The Default Planck Layout

## Path and commands

```
qmk_firmware/keyboards/planck/keymaps/frederic
```

## Installation
```
make planck/ez:frederic:flash
```

```
qmk flash -kb planck/ez -km frederic
```



# Unicode 

Last version of macos disallowed for some reasons the use of unicode
```
#define E_AIG UC(0x00E9)
#define E_GRV UC(0x00E8)
#define E_CIR UC(0x00EA)
#define E_TRM UC(0x00EB)
#define A_CIR UC(0x00E2)
#define U_GRV UC(0x00F9)
#define U_CIR UC(0x00FB)
#define C_CED UC(0x00E7)
#define EURO UC(0x20AC)
#define O_CIR UC(0x00F4)
#define O_TRM UC(0x00F6)
#define I_TRM UC(0x00EF)
#define I_CIR UC(0x00EE)
```
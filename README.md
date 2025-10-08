# 🗺️ FDF – fil de fer (French for "wireframe")

A 3D wireframe renderer built using **MiniLibX**, part of the 42 curriculum.  
Rotate, zoom, and explore 3D maps projected in isometric and parallel views.

---

## 🧭 Instructions

1. **Clone the repository**
    ```bash
    git clone <your-repo-url>
    cd <your-repo-folder>
    ```
2. **Compile the project**
    ```bash
    make
    ```
3. **If compilation fails, install the missing dependencies:**
    ```bash
    sudo apt update
    sudo apt install libx11-dev libxext-dev zlib1g-dev
    ```
4. **Run the program**
    ```bash
    ./fdf maps/<map_name>.fdf
    ```
    Try one of the sample maps included in the maps/ folder.

# FDF Controls Guide 

## 🔄 Rotation
- `1` - Tilt forward (𝛼++)  
- `2` - Spin clockwise (𝛽++)  
- `3` - Roll clockwise (𝛾++)  
- `7` - Roll counterclockwise (𝛾--)  
- `8` - Spin counterclockwise (𝛽--)  
- `9` - Tilt backwards (𝛼--)  

## 🔍 Zoom
- `+` – Zoom in  
- `-` – Zoom out  

## 🕹️ Translation 
- `W` - Move up  
- `S` - Move down  
- `A` - Move left  
- `D` - Move right  

## 📐 Projection
- `I` – Switch to isometric projection  
- `P` – Cycle through top, front, and left-side views

## 🌗 Bonus - Color Inversion
- `Spacebar` – Invert colors  

## 🆑 Reset View
- `Backspace` – Reset to default view

## ❌ Exit
- `Esc` – Exit the program

# Get the current folder path
INSTALL_DIR="$(cd "$(dirname "$0")"; pwd)"

# Step 1: Create autostart directory
mkdir -p ~/.config/autostart

# Step 2: Create the .desktop file in autostart
cat > ~/.config/autostart/IWallpaperChanger.desktop <<EOF
[Desktop Entry]
Type=Application
Name=IWallpaperChanger
Exec=$INSTALL_DIR/IWallpaperChangerKDE
Path=$INSTALL_DIR
X-GNOME-Autostart-enabled=true
EOF

echo "Install finished, please click on the exe to generate files, then place your images within the desired date."

# 
echo - n "sudoコマンド使わせていただきます。パスワードよろしく: "
sudo apt update && sudo apt upgrade -y
sudo apt install build-essential git-all
cd ~
git clone https://github.com/yoshiyuki-140/Gaussianelimination-cpp.git


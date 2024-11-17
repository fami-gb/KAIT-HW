for i in range(3):
    pswd = input("パスワードを入力：")
    if pswd == "kait1030":
        print("ログイン成功")
        break
    elif i == 2:
        print("ログイン失敗")

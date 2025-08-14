import sqlite3
import hashlib
import getpass

def connect_db():
    return sqlite3.connect('user_management.db')

def setup_database():
    with connect_db() as conn:
        conn.execute('''CREATE TABLE IF NOT EXISTS users (
                        username TEXT PRIMARY KEY,
                        password TEXT,
                        status INTEGER DEFAULT 0)''')

def hash_pw(pw):
    return hashlib.sha256(pw.encode()).hexdigest()

def create_account():
    user = input('Username: ')
    pw = getpass.getpass('Password: ')
    with connect_db() as conn:
        if conn.execute('SELECT 1 FROM users WHERE username = ?', (user,)).fetchone():
            print('Username taken.')
        else:
            conn.execute('INSERT INTO users (username, password) VALUES (?, ?)', (user, hash_pw(pw)))
            print('Registered.')

def user_login():
    user = input('Username: ')
    pw = getpass.getpass('Password: ')
    with connect_db() as conn:
        row = conn.execute('SELECT password, status FROM users WHERE username = ?', (user,)).fetchone()
        if row:
            if row[1] == 1:
                print('Already logged in.')
            elif row[0] == hash_pw(pw):
                conn.execute('UPDATE users SET status = 1 WHERE username = ?', (user,))
                print('Logged in.')
            else:
                print('Wrong password.')
        else:
            print('No user found.')

def user_logout():
    user = input('Username: ')
    with connect_db() as conn:
        row = conn.execute('SELECT status FROM users WHERE username = ?', (user,)).fetchone()
        if row:
            if row[0] == 1:
                conn.execute('UPDATE users SET status = 0 WHERE username = ?', (user,))
                print('Logged out.')
            else:
                print('Not logged in.')
        else:
            print('No user found.')

def update_password():
    user = input('Username: ')
    with connect_db() as conn:
        row = conn.execute('SELECT password, status FROM users WHERE username = ?', (user,)).fetchone()
        if row:
            if row[1] == 0:
                print('Login required.')
            else:
                old_pw = getpass.getpass('Current Password: ')
                if row[0] == hash_pw(old_pw):
                    new_pw = getpass.getpass('New Password: ')
                    conn.execute('UPDATE users SET password = ? WHERE username = ?', (hash_pw(new_pw), user))
                    print('Password updated.')
                else:
                    print('Incorrect password.')
        else:
            print('No user found.')

def menu():
    setup_database()
    actions = {
        '1': create_account,
        '2': user_login,
        '3': user_logout,
        '4': update_password
    }
    while True:
        print('\n1. Register\n2. Login\n3. Logout\n4. Change Password\n5. Quit')
        choice = input('Select: ')
        if choice == '5':
            break
        action = actions.get(choice)
        if action:
            action()
        else:
            print('Invalid.')

if __name__ == '__main__':
    menu()

class User {
    constructor(username) {
        this.username = username;
    }

    static NewUser(sql) {
        return new User(sql.username);
    }

    getUsername() {
        return this.username;
    }

}

module.exports = User;

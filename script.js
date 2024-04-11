const form = document.getElementById('registration-form');
const usernameInput = document.getElementById('username');
const passwordInput = document.getElementById('password');
const confirmPasswordInput = document.getElementById('confirm-password');

const usernames = [];

form.addEventListener('submit', function(event) {
    event.preventDefault();

    const username = usernameInput.value.trim();
    const password = passwordInput.value;
    const confirmPassword = confirmPasswordInput.value;

    if (password !== confirmPassword) {
        alert('Please make sure passwords match.');
        return;
    }

    if (usernames.includes(username)) {
        alert('Please enter another username.');
        return;
    }

    usernames.push(username);
    alert('Registration Successful!');

    form.reset();
});

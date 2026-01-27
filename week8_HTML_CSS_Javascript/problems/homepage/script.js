// ============ DARK MODE TOGGLE ============
const toggleButton = document.getElementById('theme-toggle');
const body = document.body;

// Check saved mode in localStorage
if (localStorage.getItem('theme') === 'dark') {
  body.classList.add('dark-mode');
  toggleButton.textContent = '☀️ Light Mode';
}

// Toggle theme when clicked
toggleButton.addEventListener('click', () => {
  body.classList.toggle('dark-mode');
  if (body.classList.contains('dark-mode')) {
    toggleButton.textContent = '☀️ Light Mode';
    localStorage.setItem('theme', 'dark');
  } else {
    toggleButton.textContent = '🌙 Dark Mode';
    localStorage.setItem('theme', 'light');
  }
});


if (!localStorage.getItem('visited')) {
  alert("👋 Welcome to Mohamed Tawfik’s Portfolio!");
  localStorage.setItem('visited', 'true');
}

function updateClock() {
  const clock = document.getElementById('clock');
  if (clock) {
    const now = new Date();
    clock.textContent = now.toLocaleTimeString();
  }
}
setInterval(updateClock, 1000);
updateClock();

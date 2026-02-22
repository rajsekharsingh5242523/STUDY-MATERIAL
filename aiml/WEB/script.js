const audio = document.getElementById("audioPlayer");
const playButtons = document.querySelectorAll(".controls i");

let currentButton = null;

playButtons.forEach((button) => {
  button.addEventListener("click", (e) => {
    e.stopPropagation();

    const card = button.closest(".card");
    const song = card.dataset.song;

    if (currentButton === button) {
      if (audio.paused) {
        audio.play();
        button.classList.replace("fa-play", "fa-pause");
      } else {
        audio.pause();
        button.classList.replace("fa-pause", "fa-play");
      }
      return;
    }

    if (currentButton) {
      currentButton.classList.replace("fa-pause", "fa-play");
    }

    audio.src = song;
    audio.play();

    button.classList.replace("fa-play", "fa-pause");
    currentButton = button;
  });
});
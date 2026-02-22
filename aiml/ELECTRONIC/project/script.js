// reference to the <audio> element used for playback
const audio = document.getElementById("audioPlayer");
// all play/pause icons within song cards
const playButtons = document.querySelectorAll(".controls i");

// remember which button is currently active so we can toggle it
let currentButton = null;

// attach click handlers to each icon so songs can be started or paused
playButtons.forEach((button) => {
  button.addEventListener("click", (e) => {
    // prevent the click from bubbling up to parent elements
    e.stopPropagation();

    // find the containing card and read its data-song attribute
    const card = button.closest(".card");
    const song = card.dataset.song;

    // if the same button was clicked twice, toggle playback
    if (currentButton === button) {
      if (audio.paused) {
        audio.play();
        button.classList.replace("fa-play", "fa-pause");
      } else {
        audio.pause();
        button.classList.replace("fa-pause", "fa-play");
      }
      return; // exit early since no new track was selected
    }

    // if another button was active, reset its icon
    if (currentButton) {
      currentButton.classList.replace("fa-pause", "fa-play");
    }

    // switch audio element to the new track URL and start playing
    audio.src = song;
    audio.play();

    // update icon of clicked button and track it as current
    button.classList.replace("fa-play", "fa-pause");
    currentButton = button;
  });
});
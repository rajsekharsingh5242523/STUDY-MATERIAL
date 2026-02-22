<!doctype html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/7.0.1/css/all.min.css"
      integrity="sha512-2SwdPD6INVrV/lHTZbO2nodKhrnDdJK9/kg2XD1r9uGqPo1cUbujc+IYdlYdEErWNu69gVcYgdxlmVmzTWnetw=="
      crossorigin="anonymous"
      referrerpolicy="no-referrer"
    />
    <link rel="stylesheet" href="styles.css" />
    <title>Music Player UI</title>
    <script src="script.js" defer></script>
  </head>
  <body>
    <div class="navbar">
      <i class="fa-solid fa-headphones"></i>
      <h3>Music Player</h3>
    </div>
    <div class="songs">
      <div class="card" data-song="audio/BlindingLights.mp3">
        <img src="pics/BlindingLights.jpeg" alt="albumpic" />
        <h3>Blinding Lights</h3>
        <h5>The Weeknd</h5>
        <div class="controls">
          <i class="fa-solid fa-play"></i>
        </div>
      </div>
      <div class="card" data-song="audio/Levitating.mp3">
        <img src="pics/Levitating.jpeg" alt="albumpic" />
        <h3>Levitating</h3>
        <h5>Dua Lipa</h5>
        <div class="controls">
          <i class="fa-solid fa-play"></i>
        </div>
      </div>
      <div class="card" data-song="audio/UptownFunk.mp3">
        <img src="pics/UptownFunk.jpeg" alt="albumpic" />
        <h3>Uptown Funk</h3>
        <h5>Mark Ronson ft. Bruno Mars</h5>
        <div class="controls">
          <i class="fa-solid fa-play"></i>
        </div>
      </div>
      <div class="card" data-song="audio/ShapeOfYou.mp3">
        <img src="pics/ShapeOfYou.jpeg" alt="albumpic" />
        <h3>Shape Of You</h3>
        <h5>Ed Sheeran</h5>
        <div class="controls">
          <i class="fa-solid fa-play"></i>
        </div>
      </div>
      <div class="card" data-song="audio/SmoothOperator.mp3">
        <img src="pics/SmoothOperator.jpeg" alt="albumpic" />
        <h3>Smooth Operator</h3>
        <h5>Sade</h5>
        <div class="controls">
          <i class="fa-solid fa-play"></i>
        </div>
      </div>
    </div>
    <footer class="audio-footer">
      <audio id="audioPlayer" controls>
        <source src="BlindingLights" type="audio/mpeg">
        Your browser does not support the audio element.
      </audio>
    </footer>

  </body>
</html>




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


*{
  font-family: system-ui, sans-serif;
  box-sizing: border-box;
}

body{
  margin:0;
  background:#0B0F19;
  color:#fff;
}

.navbar{
  height:60px;
  background:#0A0F1C;
  color:#fff;
  display:flex;
  align-items:center;
  gap:10px;
  font-size:28px;
  border-bottom:2px solid #3B82F6;
}

.navbar i{ 
  margin-left:20px; 
}

.songs{
  display:flex;
  justify-content:center;
  flex-wrap:wrap;
  gap:25px;
  margin:50px 0 120px;
}

.card{
  background:#121826;
  border:1px solid #1F2937;
  width:215px;
  height:350px;
  padding:12px;
  border-radius:12px;
  display:flex;
  flex-direction:column;
  align-items:center;
  transition:.3s;
}

.card:hover{
  transform:translateY(-6px);
  border-color:#3B82F6;
  box-shadow:0 0 15px #3B82F6;
}

.card img{
  width:100%;
  height:200px;
  object-fit:cover;
  border-radius:10px;
}

.card h5{ 
  color:#9CA3AF; margin:0; 
}

.controls{
  margin-top: 10px;
}
.audio-footer{
  position: fixed;
  bottom: 0;
  width: 100%;
  height: 90px;
  background: #0A0F1C;
  border-top: 2px solid #3B82F6;
  display: flex;
  align-items: center;
  justify-content: center;
}

#audioPlayer{
  width: 90%;
  filter: invert(1) brightness(1.2);
}
from machine import Pin
import time
from time import sleep
import network
import socket

SSID="Redmi A4 5G"
PASSWORD="sonu1234"
def connect_wifi():
    wlan=network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID,PASSWORD)
    while not wlan.isconnected():
        time.sleep(1)
    print("connected,ip:", wlan.ifconfig()[0])
    return wlan.ifconfig()[0]
connect_wifi()
AIN1=Pin(25,Pin.OUT)
AIN2=Pin(33,Pin.OUT)
BIN1=Pin(27,Pin.OUT)
BIN2=Pin(14,Pin.OUT)
STBY=Pin(26,Pin.OUT)
pwma=Pin(32,Pin.OUT)
pwmb=Pin(12,Pin.OUT)
pwma.on()
pwmb.on()
STBY.on()
TRIG= PIN(2,Pin.OUT)
ECHO= Pin(4,Pin.IN)

def  forward():
    AIN1.on();
    AIN2.off();
    BIN1.on();
    BIN2.off();
def backward():
    AIN1.off();
    AIN2.on();
    BIN1.off();
    BIN2.on();
def right():
    AIN1.on();
    AIN2.off();
    BIN1.off();
    BIN2.on();
def left():
    AIN1.off();
    AIN2.on();
    BIN1.on();
    BIN2.off();
def stop():
    STBY.off();
    
def measure_distance():
    TRIG.off()
    time.sleep_us(2)
    TRIG.on()
    time.sleep_us(10)
    TRIG.off()
    try:
        pulse=time_pulse_us(ECHO,1,30000)
        if pulse<0:
            return None
        
        distance=(pulse/2)/29.1
        return dist_cm
    except:
        return None
    
def login_page():
    return """
        <!DOCTYPE html>
<html lang="en">
  <head>
    <title>Login</title>
    <style>
      body {
        background: linear-gradient(135deg, #000000, #0a0f1f, #001f2d);
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        color: white;
        display: flex;
        padding: 40px;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
        animation: fadeIn 1.2s ease-in-out;
      }

      .login-container {
        display: flex;
        flex-direction: column;
        align-items: center;
        gap: 50px;
      }

      .login-box {
        background: rgba(0, 0, 0, 0.85);
        padding: 32px;
        border-radius: 15px;
        justify-content: center;
        border: 1px solid cyan;
        box-shadow: 0 0 12px rgba(0, 255, 255, 0.2);
        width: 350px;
        max-width: 90%;
        transition: transform 0.3s ease, box-shadow 0.3s ease;
      }
      .login-box:hover {
        transform: scale(1.03);
        box-shadow: 0 0 20px rgba(0, 255, 255, 0.3);
      }

      h2 {
        text-align: center;
        color: cyan;
        letter-spacing: 1px;
        text-shadow: 0 0 3px cyan;
      }

      input[type="text"],
      input[type="password"] {
        width: 100%;
        padding: 12px;
        margin: 12px 0;
        border: none;
        border-radius: 8px;
        font: inherit;
        box-sizing: border-box;
        background: rgba(255, 255, 255, 0.95);
        color: black;
        transition: all 0.3s ease;
      }
      input[type="text"]:focus,
      input[type="password"]:focus {
        outline: none;
        border: 1px solid cyan;
        box-shadow: 0 0 6px rgba(0, 255, 255, 0.4);
      }

      /* Buttons */
      button {
        width: 100%;
        padding: 12px;
        background: linear-gradient(90deg, cyan, #00ffaa);
        color: black;
        border: none;
        border-radius: 8px;
        cursor: pointer;
        font-weight: bold;
        font: inherit;
        margin-top: 16px;
        transition: all 0.3s ease;
      }
      button:hover {
        background: linear-gradient(90deg, #00ffaa, cyan);
        transform: translateY(-1px);
        box-shadow: 0 0 8px rgba(0, 255, 255, 0.4);
      }

      .click {
        background: transparent;
        border: 1px solid cyan;
        color: cyan;
        transition: all 0.3s ease;
      }
      .click:hover {
        background: cyan;
        color: black;
        box-shadow: 0 0 6px rgba(0, 255, 255, 0.4);
      }

      .name {
        text-align: center;
        color: cyan;
        font-size: 1.5rem;
        line-height: 1.4;
        text-shadow: 0 0 4px rgba(0, 255, 255, 0.6);
      }
      .info {
        margin: 0;
        font-family: 'Share Tech Mono', monospace;
        font-size: 40px;
        font-weight: bold;
        color: whitesmoke;
        letter-spacing: 3px;
        text-transform: uppercase;
        text-shadow: 0 0 6px rgba(0, 255, 255, 0.6);
      }

      @keyframes fadeIn {
        from {
          opacity: 0;
          transform: scale(0.97);
        }
        to {
          opacity: 1;
          transform: scale(1);
        }
      }
    </style>
  </head>

  <body>
    <div class="login-container">
      <form class="login-box" method="POST" action="/login">    
        <h2>Login</h2>
        <input type="text" name="Username" placeholder="Username" required />   <!-- type="date" tells the browser what kind of input field this should be. -->
        <input type="password" name="password" placeholder="Password" required />
        <button class="click">SIGN UP</button>
        <button class="click">SIGN IN</button>
      </form>

      <div class="name">
        <h2 class="name"><strong>HANDS ON ROBOTICS</strong></h2>
        <p>By <b>Robotics Club</b></p>
        <p><b>Rajsekhar Singh</b></p>
      </div>
    </div>
    <script></script>
  </body>
</html>

"""


def html_page():
    return"""
    <!DOCTYPE html>
<html>
    <head>
        <title>Contol Bot</title>
        <style>
            body{
                padding-top: 20px;
                font-family:Arial,sans-serif;
                color: whitesmoke;
                background-color:black;
                display:flex;   /*Flexbox --Works in one dimension → either a row (horizontal) or a column (vertical).*/
                font-size:1.5rem;
                flex-direction:column;
                align-items:center;
                margin:0;
                }
            h1{
                text-align: center;
                color:cyan;
            }
            .button,.info{
                background-color: dimgrey;
                color:cyan;
                margin-bottom: 10px;
            }
            .button-container{
                display:grid;       /*Grid -- Works in two dimensions → rows and columns together.*/
                grid-template-columns:1fr 1fr 1fr;
                grid-template-rows:1fr 1fr 1fr;
                gap:10px;
                width:300px;
                height:300px;       
                margin-bottom:30px;
            }
            .button{
                padding:15px 30px;
                font-size:16px;
                font-weight:bold;
                background:black;
                color: cyan;
                border:2px solid cyan;
                border-radius: 12px;
                cursor:pointer;
                display:flex;
                align-items:center;
                justify-content:center;
                text-decoration:none;
                transition:all 0.2s;
            }
            .button:hover{          /* :hover → This is a pseudo-class that applies the style only when the user moves the mouse pointer over the element. */
                background-color:    cyan;
                color: #000;
                box-shadow:0 6px 15px rgba(0,255,180,0.5);        /* 0 → horizontal offset (no left-right shift) 6px → vertical offset (shadow falls 6px below the button)
                                                                    15px → blur radius (how soft/spread the shadow looks)

                                                                    rgba(0,255,180,0.5) → color of the shadow (a semi-transparent greenish-cyan glow).*/    
                transform:translateY(-8px);     /*Moves the button 8px upward when hovered, creating a "lift" effect.*/
            }
            .button:active{transform:translateY(0);}
            .center-dot{
                width:16px;
                height:16px;
                background-color:cyan;
                border-radius:50%;
                align-self:center;
                justify-self:center; 
            }
            .info{
                background-color: black;
                margin-top:30px;
                font-size:18px;
                padding:15px 30px;
                border-radius:8px;
                color: whitesmoke;
                border: 2px solid cyan;
            }
            .forward{grid-column:2;grid-row:1;}
            .left{grid-column:1;grid-row:2;}
            .right{grid-column:3;grid-row:2;}
            .backward{grid-column:2;grid-row:3;}
            .center-dot{grid-column:2;grid-row:2;}
            .name{
                text-align: center;
                margin-top: 20px;
                color: cyan;
                font-size: 1.3rem;
                line-height: 1.4;
            }
   
           
        </style>
    </head>
    <body>
        <div class="button-container">
            <div class="button forward" onmousedown="sendCommand('forward',true)" onmouseup="sendCommand('forward',false)" ontouchstart="sendCommand('forward',true)" ontouchend="sendCommand('forward',false)">forward</div>
            <div class="button left  onmousedown="sendCommand('left',true)" onmouseup="sendCommand('left',false)" ontouchstart="sendCommand('left',true)" ontouchend="sendCommand('left',false)">left</div>
            <div class="center-dot "></div>
            <div class="button backward onmousedown="sendCommand('right',true)"  onmouseup="sendCommand('right',false)" ontouchstart="sendCommand('right',true)" ontouchend="sendCommand('right',false) ">backward</div>
            <div class="button right  onmousedown="sendCommand('backward',true)" onmouseup="sendCommand('backward',false)" ontouchstart="sendCommand('backward',true)" ontouchend="sendCommand('backward',false) ">right</div>
        </div>
        <div class="info" id="distance">Loading.....</div>      <!-- Use id for one unique element.Use class for groups of elements with shared styling/behavior.-->
        <div>
            <p>By<b> Robotics Club</b></p>       <!-- to make it bolder use <b> -->
        </div>

        <script>
            function updateDistance() {
                fetch('/distance')
                    .then(res => res.text())
                    .then(data => {
                        document.getElementById("distance").innerText = data;
                    });
            }
            setInterval(updateDistance, 500);
            window.onload = updateDistance;
            // Movement handling (hold button = move, release = stop)
            function sendCommand(cmd, isDown) {
                fetch(isDown ? '/' + cmd : '/stop');
            }
        </script>
    </body>

</html>

"""


USERNAME = 'Adminsonu'
PASSWORD_AUTH ='1234'
session=False



def handle_client():
    global session
    request= client.recv(1024).decode("utf-8")
    print('request')
    method= request.split('')[0]
    path=request.split('')[1]
    
    
    if path.startswith('/login') and method==='POST':
        body= request.split("\r\n\r\n")[-1]
        data= {}
        print(data)
        #HERE data is login=xyz password=abcd& .....
        for pair in body.split('&'):
            if "=" in pair:
                key,value=pair.split('=')
                data[key]= value
        username= data.get("username")
        password=data.get('password')
        if usernaem==USERNAME and password == PASSWORD_AUTH:
            session= True
            client.send("HTTP/1.1 302 Found\r\nLocation: /\r\n\r\n")
        else:
            session= False
            client.send('HTTP/1.1 401 Unauthorized\r\n\r\n<h1>Unauthorized</1>')
        client.close()
        return
    if not session  and path != "/login":
        client.send('HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n')
        client.send(login_page())
        client.close()
        return
    if path="/distance":
        dist=measure_distance()
        if dist is None or dist>100:
            msq="no obstacles detected"
        else:
            msg=f'Obstical detected ahead: {dist:.2f} cm'
        client.send("HTTP/1.1 200 OK\r\ncontent-Type : text/plain\r\n\r\n")
        client.send(msg)
        client.close()
        return
    if path == "/forward":
        forward()
    elif path=="/backward"
         backward()
    elif path=="/left":
        left()
    elif path=="/right":
        right()
    elif path=="/stop":
        stop()
    else:
        stop()
        
    client.send("HTTP/1.1 200 OK\r\nconect-Type: text/html\r\n\r\n")
    client.send(html_page())
    client.close()

ip= coonect_wifi()

addr= socket.getaddrinfo(ip,80)[0][-1]
s= socket.socket()
s.bind(addr)
s.listen(1)
print("listening on",addr)

while True:
    try:
        client,addr=s.accept()
        handle_client(client)
    except Exception as e:
        print("Error:",e)
        
        
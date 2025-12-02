// ================ Miscellaneous JavaScript ==========================
alert('hello'); // Greeting alert

console.log(2 + 2); // Simple math

let variable = 3;       // let allow to change the value of variable

console.log(variable);  // way to display the output in console

variable = 15;

console.log(`changed let data: ${variable}`);     // works like python print(f"changed let data :{console.log(variable)")

const variable2 = 'hello';        //does not allow to change the value of the variable

console.log(typeof variable2);    //display the output of what type of thing is it


const age = 17;

console.log(age >= 18 ? `you are eligible to drive` : `you cannot drive`); // Ternary operator shortcut for  if(age >=18){console.log(`you are eligible to drive`)}else {console.log(`you cannot drive')}


console.log(3 == '3.00');   // Loose equality (true)

console.log(3 === '3.00');  // Strict equality (false)

mySecArray = [
    'rajsekhar singh',
    8660666968,
    { age: 18, address: 'b206,;vs elegance,k v layout,k r puram ,blore-560036' },
    true
];       //this is show that array can hold many type of data and also how that array is also data type as it can be consider as a variable

console.log(mySecArray);

console.log(typeof mySecArray); //because a is object because see (array.push) same things like this function array(){push:.....}

console.log(Array.isArray(mySecArray)); //this is the way to check if it is a array

console.log(mySecArray.length);        //this return the length of the array

mySecArray.push('dance');              //this pushes the element inside the bracket inside the array

console.log(mySecArray);

console.log(`first element :${mySecArray[0]}`);        //to access the elements of the array then i.e.. array name [index]

mySecArray.splice(0, 2);         // it remove the elements from the index mention first and consider the first mention index count to how many index mention that may time dlect from original index

console.log(mySecArray);

mySecArray.splice(0, 1);

console.log(mySecArray);



// ---------- Object and JSON example ----------
// Sample object for demonstration of nested properties and JSON handling
const project = {
    details: {
        'first-name': 'rajsekhar',
        'last-name': 'singh',
        Address: 'b 206, lvs elegance, k r puram, bangalore-560036'
    },
    stars: 4.5,
    function: function print(text) {
        console.log(text);
    }
};

let data = JSON.stringify(project);        // Convert the project object to a string

console.log("Project (stringified):", data);
console.log("Project (parsed):", JSON.parse(data));





// =================Rock Paper Scissor Logic =====================

// Load score object from localStorage or initialize with default values if not present.
// This ensures persistent score tracking across page reloads.
let score = JSON.parse(localStorage.getItem('SCORE')) || {
    win: 0,
    lost: 0,
    tie: 0
};


// function <name> (input) {code.....}
function playGame(userChoice) {
    const num = Math.random();        //generates a number between 0 and 1

    let computer_Move = '';

    if (num < 1 / 3) {
        computer_Move = 'ROCK';
    } else if (num < 2 / 3) {
        computer_Move = 'PAPER';
    } else {
        computer_Move = 'SCISSOR';
    }

    console.log(`User: ${userChoice}, Computer: ${computer_Move}`);

    let RESULT = '';
    user_Choice = userChoice;

    // Determine game result  in a smart way
    if (userChoice === computer_Move) {
        RESULT = "It's a TIE!";
        score.tie++;
    } else if (
        (userChoice === 'ROCK' && computer_Move === 'SCISSOR') ||
        (userChoice === 'PAPER' && computer_Move === 'ROCK') ||
        (userChoice === 'SCISSOR' && computer_Move === 'PAPER')
    ) {
        RESULT = "YOU WIN 🎉";
        score.win++;
    } else {
        RESULT = "Computer WINS ☹";
        score.lost++;
    }

    console.log(score);

    // Save updated score to localStorage
    localStorage.setItem('SCORE', JSON.stringify(score));   // here data is storged in SCORE in string form 

    document.querySelector('.js-Results-display').innerHTML = `${RESULT}`;
    document.querySelector('.js-choice-display').innerText = `you choice: ${userChoice} <--->computer choice: ${computer_Move}`;
    document.querySelector(".js-score-value").innerHTML = `win: ${score.win}, lost: ${score.lost}, tie: ${score.tie}`;
}


// Resets the score object and updates both localStorage and the display
function resetScore() {
    score = { win: 0, lost: 0, tie: 0 };      // reset in-memory score object

    localStorage.setItem('SCORE', JSON.stringify(score));     // update localStorage

    alert("Score has been reset!");

    document.querySelector(".js-score-value").innerHTML = `win: ${score.win}, lost: ${score.lost}, tie: ${score.tie}`;
    document.querySelector(".js-Results-display").innerText = '';
    document.querySelector(".js-choice-display").innerText = '';
}



// ==================Cart Tracker Logic ===============
let cartQty = 0; // Initial cart quantity

// ====================calculate shipping cost ==========================
function calculateShippingCost() {

    // DOM returns string, so we convert it to number
    inputnum = Number(document.querySelector(".js-cost-input").value);

    // the <input> does not have innerHTML because it doesn't have a closing tag
    // we use .value to access the value directly entered by the user
    console.log(`input number type : ${typeof inputnum}`);

    outputnum = 0; // default output

    // If order is under $40, add $10 shipping
    if (inputnum < 40 && inputnum > 0) {
        outputnum = inputnum + 10;
        document.querySelector(".output_num").innerHTML = outputnum.toFixed(2); // .toFixed  make it to the mention decimal error;
    }
    else if (inputnum === 0) {
        alert('Error: Enter a value');
        document.querySelector(".output_num").innerText = '';
    }
    else if (document.querySelector('.js-cost-input').value < 0) {
        alert('Error: cost cannot be less than $0');
        document.querySelector(".output_num").innerText = '';
    }
    else {
        outputnum = inputnum;
        document.querySelector(".output_num").innerHTML = outputnum.toFixed(2);
    }
}



// ==================== YouTube Subscribe Toggle ==========================
function subscribe_button_change() {
    const buttonElement = document.querySelector('.js-subscribe-button'); // selects the button

    console.log(buttonElement);

    if (buttonElement.innerText === 'Subscribe') {
        buttonElement.innerText = 'Subscribed';
        buttonElement.classList.add('is-Subscribed');
    }
    else {
        buttonElement.innerText = 'Subscribe';
        buttonElement.classList.remove('is-Subscribed');
    }

    // don't put spaces around the innerHTML of button
    // dont need to put . for classList.add(....)
    // because even though it doesn't create a code error,
    // in innerHTML it also considers spaces as visible characters.
    // So use .innerText when you want to avoid that issue.
}



// Demonstrates type coercion: string '25' is converted to number automatically
String(25);

console.log('25' - 5); // here JavaScript automatically converts the string into an integer


// Logs the body of the HTML document
window.console.log(document.body); //window represent the the whole window we use window automatically

// Logs the first <button> element in the document
console.log(document.querySelector('button'));

// Logs the button with class "second-button"
console.log(document.querySelector('.second-button'));



// ==================== Toggle Button Color ==========================
function change_colour(toggled) {
    if (document.querySelector(toggled).classList.contains('buttons_black')) {
        document.querySelector(toggled).classList.remove('buttons_black');
    }
    else {
        document.querySelector(toggled).classList.add('buttons_black');
    }
}



// =======================TODO LIST ================================
myArray = [];

function todo_list() {
    data = document.querySelector('.todo_list_practice-box').value;     // here value to get the input thing
    date = document.querySelector('.todo_list_date').value;  
    if (date==''){alert('Please enter the date')}
    else{myArray.push({name:data,date:date});}
  
    console.log(myArray);

    todo_display();
}


let i = 0;

function todo_display() {
    let todolist_html = '';

    /*for (loop variable ; conditon ; loop variable incrementing ) {}  */ 
    for (let i = 0; i < myArray.length; i++) {
        console.log(i);
        DATA=myArray[i]
        const output_name = DATA.name;
        const output_date = DATA.date;
        console.log(output_date,output_name)        /* here below div occupies a full line in the page that is why we may get in separte line with out the grid*/ 
        const todo_html = `
            <div>${output_name}</div>       
            <div>${output_date}</div>
            <button  class='delete-todo-button' onclick="delect_todo_list(${i})">
                Delete
            </button> 
        `
        todolist_html += todo_html
    }

    console.log(todolist_html);

    document.querySelector('.todo_list_output').innerHTML = todolist_html;  /* here the above created  html element is taken is pushed into div block  */ 

}

function delect_todo_list(Index){
    myArray.splice(Index,1)
    console.log(myArray)
    todo_display()
}


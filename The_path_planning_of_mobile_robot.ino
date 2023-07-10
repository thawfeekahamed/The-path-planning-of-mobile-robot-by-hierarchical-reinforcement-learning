// This is an Obstacle Avoiding Robot using Reinforcement Learning/AI
// Author of this Project: Varun Walimbe
// Algorithm used in this project: Q learning

// Pins used for ultrasonic sensor
int TRIG_PIN = 7;
int ECHO_PIN = 8;

// Pins used for DC motors
int M1 = 13;
int M2 = 12;
int M3 = 11;
int M4 = 10;

// Variable to store distance
int duration;
float distance;

// Variable to store obstacle state
bool Obstacle = false;

// Variable to store action
int ACTION = 0;

// Variable to store state
int STATE = 0;

// Variable to store next state
int NEXT_STATE;

// Variable to store reward
int REWARD;

// Variable to store epsilon
float EPSILON = 0.90;

// Variable to store learning rate
float ALPHA = 0.1;

// Variable to store discount factor
float GAMMA = 0.5;

// Define the dimensions of the Q array
const int STATE_COUNT = 2;  // Number of possible states
const int ACTION_COUNT = 4; // Number of possible actions

// Declare and define the Q array
int Q[STATE_COUNT][ACTION_COUNT] = {
  {0, 0, 0, 0}, // Values for state 0
  {0, 0, 0, 0}  // Values for state 1
};

// Function to check if there is an obstacle
bool Obstacle_Avoider() {
  // TODO: Implement this function to check if there is an obstacle
  return false;
}

// Function to randomly choose an action
int RANDOM(float epsilon) {
  if (random(0, 100) < epsilon * 100) {
    return random(0, 4);
  } else {
    return ARGMAX(Q[STATE], ACTION_COUNT);
  }
}

// Function to find the maximum value in an array
int ARGMAX(int *array, int size) {
  int max_value = array[0];
  int max_index = 0;
  for (int i = 1; i < size; i++) {
    if (array[i] > max_value) {
      max_value = array[i];
      max_index = i;
    }
  }
  return max_index;
}

// Function to execute an action
void Execute_Action(int action) {
  switch (action) {
    case 0:
      Forward();
      break;
    case 1:
      Backward();
      break;
    case 2:
      Left();
      break;
    case 3:
      Stop();
      break;
    default:
      break;
  }
}

// Function to calculate the reward
int Calculate_Reward(int state, int action) {
  if (state == 0 && action == 0) {
    return 10;
  } else if (state == 1 && action == 3) {
    return 10;
  } else {
    return -1;
  }
}

// Function to update the Q table
void Update_Q(int state, int next_state, int action, int reward, float alpha, float gamma) {
  Q[state][action] = Q[state][action] + alpha * (reward + gamma * Q[next_state][ARGMAX(Q[next_state], ACTION_COUNT)] - Q[state][action]);
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pins as output
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
}

void loop() {
  // Check if there is an obstacle
  Obstacle = Obstacle_Avoider();

  // If there is an obstacle, set state to 1
  if (Obstacle) {
    STATE = 1;
  }
  // If there is no obstacle, set state to 0
  else {
    STATE = 0;
  }

  // Randomly choose an action or use the Q table to choose an action
  ACTION = RANDOM(EPSILON);

  // Execute the action
  Execute_Action(ACTION);

  // Calculate the reward
  REWARD = Calculate_Reward(STATE, ACTION);

  // Get next state
  Obstacle = Obstacle_Avoider();
  NEXT_STATE = Obstacle ? 1 : 0;

  // Update the Q table
  Update_Q(STATE, NEXT_STATE, ACTION, REWARD, ALPHA, GAMMA);
}

// Function definitions for controlling motors
void Forward() {
  // TODO: Implement forward motion logic
}

void Backward() {
  // TODO: Implement backward motion logic
}

void Left() {
  // TODO: Implement left motion logic
}

void Stop() {
  // TODO: Implement stop motion logic
}


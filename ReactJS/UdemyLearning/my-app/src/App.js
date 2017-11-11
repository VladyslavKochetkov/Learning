import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

class App extends Component {
  constructor(props){
    super(props);
    this.state={
      text: "Text One"
    };
  }

  render() {
    return (
      <div className="App">
        <button id={"button1"}>{this.state.text}</button>
        <p id={"p1"} value={this.state.p1value}></p>
      </div>
    );
  }
}

export default App;

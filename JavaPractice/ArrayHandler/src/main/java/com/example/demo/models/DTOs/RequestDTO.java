package com.example.demo.models.DTOs;

public class RequestDTO {
    private String what;
    private int[] numbers;

    public String getWhat() {
        return what;
    }

    public void setWhat(String what) {
        this.what = what;
    }

    public int[] getNumbers() {
        return numbers;
    }

    public void setNumbers(int[] numbers) {
        this.numbers = numbers;
    }

    public RequestDTO(String what, int[] numbers) {
        this.what = what;
        this.numbers = numbers;
    }
}

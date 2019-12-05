package com.example.demo.models.DTOs;

public class IntResponseDTO implements ResponseDTO {
    private int result;

    public int getResult() {
        return result;
    }

    public void setResult(int result) {
        this.result = result;
    }

    public IntResponseDTO() {
    }

    public IntResponseDTO(int result) {
        this.result = result;
    }
}

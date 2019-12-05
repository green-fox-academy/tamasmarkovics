package com.example.demo.models.DTOs;

public class ArrayResponseDTO implements ResponseDTO {
    private int[] result;

    public int[] getResult() {
        return result;
    }

    public void setResult(int[] result) {
        this.result = result;
    }

    public ArrayResponseDTO() {
    }

    public ArrayResponseDTO(int[] result) {
        this.result = result;
    }
}

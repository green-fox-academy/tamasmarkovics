package com.example.demo.models.DTOs;

public class SithRequestDTO {
    private String text;

    public SithRequestDTO() {
    }

    public SithRequestDTO(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}

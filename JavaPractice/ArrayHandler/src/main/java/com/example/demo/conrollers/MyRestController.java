package com.example.demo.conrollers;

import com.example.demo.models.DTOs.*;
import com.example.demo.services.HandlerService;
import com.example.demo.services.LoggingService;
import com.example.demo.services.SithService;
import com.example.demo.services.TranslatorService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.Arrays;

@RestController
public class MyRestController {
    private HandlerService handlerService;
    private LoggingService loggingService;
    private SithService sithService;
    private TranslatorService translatorService;

    @Autowired
    public MyRestController(HandlerService handlerService, LoggingService loggingService,
                            SithService sithService, TranslatorService translatorService) {
        this.handlerService = handlerService;
        this.loggingService = loggingService;
        this.sithService = sithService;
        this.translatorService = translatorService;
    }

    @PostMapping(value = "/arrays")
    public ResponseEntity arrayController(@RequestBody(required = false) RequestDTO data) {
        try {
            this.loggingService.save(data.getWhat(), Arrays.toString(data.getNumbers()));
            return ResponseEntity.status(HttpStatus.OK).body(handlerService.arrayHandler(data));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.OK).body(new ErrorDTO(e.getMessage()));
        }
    }

    @PostMapping(value = "/sith")
    public ResponseEntity sithController(@RequestBody(required = false) SithRequestDTO sithRequestDTO) {
        try {
            return ResponseEntity.status(HttpStatus.OK).body(sithService.sithResponse(sithRequestDTO));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.OK).body(new SithErrorDTO(e.getMessage()));
        }
    }

    @PostMapping(value = "/translate")
    public ResponseEntity translator(@RequestBody(required = false) TranslatorRequestDTO data) {
        try {
            return ResponseEntity.status(HttpStatus.OK).body(translatorService.translatorResponse(data));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.OK).body(new ErrorDTO(e.getMessage()));
        }
    }

    @GetMapping(value = "/log")
    public ResponseEntity logger(@RequestParam(name = "count", required = false) Integer count,
                                 @RequestParam(name = "page", required = false) Integer page,
                                 @RequestParam(name = "q", required = false) String q) {
        try {
            return ResponseEntity.status(HttpStatus.OK).body(loggingService.getLogEntriesWithCount(count, page, q));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_ACCEPTABLE).body(new ErrorDTO(e.getMessage()));
        }
    }


}

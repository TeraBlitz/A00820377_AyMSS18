import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { MateriasPrimasService } from '../../../services/materias-primas.service';

@Component({
  selector: 'app-materias-primas-list',
  templateUrl: './materias-primas-list.component.html',
  styleUrls: ['./materias-primas-list.component.scss']
})
export class MateriasPrimasListComponent implements OnInit {
  public mps: any;

  constructor(
    private mpService: MateriasPrimasService,
    private route: ActivatedRoute
  ) {
    this.mps = [];
  }

  ngOnInit() {
    this.mpService.getMps().subscribe((response: any) => {
      this.mps = response.items;
    });
  }
}
